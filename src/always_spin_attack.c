#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "recompui.h"
#include "z64recomp_api.h"

RecompuiContext context;
RecompuiResource root;
RecompuiResource container;
RecompuiResource button;
RecompuiResource button2;
RecompuiResource textinput;
RecompuiResource textinput_button;

bool context_shown = false;

void button_pressed(RecompuiResource resource, const RecompuiEventData* data, void* userdata) {
    if (data->type == UI_EVENT_CLICK) {
        if (resource == button) {
            recomp_printf("Pressed button 1\n");
        }
        else {
            recomp_printf("Pressed close button\n");
            recompui_hide_context(context);
            context_shown = false;
        }
    }
}

void textinput_enter_pressed(RecompuiResource resource, const RecompuiEventData* data, void* userdata) {
    if (data->type == UI_EVENT_CLICK) {
        char* textinput_value = recompui_get_input_text(textinput);
        recomp_printf("  Textinput submitted: %s\n", textinput_value);
        recomp_free(textinput_value);
    }
}

RECOMP_CALLBACK("*", recomp_on_init)
void on_init() {
    RecompuiColor bg_color;
    bg_color.r = 255;
    bg_color.g = 255;
    bg_color.b = 255;
    bg_color.a = 0.1f * 255;

    RecompuiColor border_color;
    border_color.r = 255;
    border_color.g = 255;
    border_color.b = 255;
    border_color.a = 0.2f * 255;

    RecompuiColor modal_color;
    modal_color.r = 8;
    modal_color.g = 7;
    modal_color.b = 13;
    modal_color.a = 0.9f * 255;

    const float body_padding = 64.0f;
    const float modal_height = RECOMPUI_TOTAL_HEIGHT - (2 * body_padding);
    const float modal_max_width = modal_height * (16.0f / 9.0f);
    const float modal_border_width = 1.1f;
    const float modal_border_radius = 16.0f;

    context = recompui_create_context();
    recompui_open_context(context);

    root = recompui_context_root(context);
    // Set up the root element so it takes up the full screen.
    recompui_set_position(root, POSITION_ABSOLUTE);
    recompui_set_top(root, 0, UNIT_DP);
    recompui_set_right(root, 0, UNIT_DP);
    recompui_set_bottom(root, 0, UNIT_DP);
    recompui_set_left(root, 0, UNIT_DP);
    recompui_set_width_auto(root);
    recompui_set_height_auto(root);

    // Set up the root element's padding so the modal contents don't touch the screen edges.
    recompui_set_padding(root, body_padding, UNIT_DP);
    recompui_set_background_color(root, &bg_color);

    // Set up the flexbox properties of the root element.
    recompui_set_flex_direction(root, FLEX_DIRECTION_COLUMN);
    recompui_set_justify_content(root, JUSTIFY_CONTENT_CENTER);

    // Create a container to act as the modal background and hold the elements in the modal.
    container = recompui_create_element(context, root);

    // Take up the full height and full width, up to a maximum width.
    recompui_set_height(container, 100.0f, UNIT_PERCENT);
    recompui_set_flex_grow(container, 1.0f);
    recompui_set_max_width(container, modal_max_width, UNIT_DP);

    // Set up the flexbox properties of the container.
    recompui_set_display(container, DISPLAY_FLEX);
    recompui_set_justify_content(container, JUSTIFY_CONTENT_FLEX_START);
    recompui_set_flex_direction(container, FLEX_DIRECTION_ROW);
    recompui_set_padding(container, 16.0f, UNIT_DP);
    recompui_set_gap(container, 16.0f, UNIT_DP);
    recompui_set_align_items(container, ALIGN_ITEMS_BASELINE);
    
    // Set up the container to be the modal's background.
    recompui_set_border_width(container, modal_border_width, UNIT_DP);
    recompui_set_border_radius(container, modal_border_radius, UNIT_DP);
    recompui_set_border_color(container, &border_color);
    recompui_set_background_color(container, &modal_color);

    // Create some buttons.
    button = recompui_create_button(context, container, "Mod button", BUTTONSTYLE_PRIMARY);
    recompui_set_text_align(button, TEXT_ALIGN_CENTER);
    
    button2 = recompui_create_button(context, container, "Close", BUTTONSTYLE_SECONDARY);
    recompui_set_text_align(button2, TEXT_ALIGN_CENTER);

    // Bind the shared callback to the two buttons.
    recompui_register_callback(button, button_pressed, NULL);
    recompui_register_callback(button2, button_pressed, NULL);

    // Create a text input
    textinput = recompui_create_textinput(context, container);
    recompui_set_flex_grow(textinput, 1.0f);
    recompui_set_font_size(textinput, 30.0f, UNIT_DP);

    // Create a button to correspond to the text input
    textinput_button = recompui_create_button(context, container, "Start", BUTTONSTYLE_SECONDARY);
    recompui_set_text_align(textinput_button, TEXT_ALIGN_CENTER);
    recompui_set_flex_basis(textinput_button, 150.0f, UNIT_DP);
    recompui_set_flex_grow(textinput_button, 0.0f);
    recompui_set_flex_shrink(textinput_button, 0.0f);

    // Bind the callback for the text input button.
    recompui_register_callback(textinput_button, textinput_enter_pressed, NULL);
    
    recompui_close_context(context);

    context_shown = false;
}

// Patches a function in the base game that's used to check if the player should quickspin.
RECOMP_PATCH s32 Player_CanSpinAttack(Player* this) {
    recomp_printf("enum_option: %d\n", recomp_get_config_u32("enum_option"));
    recomp_printf("number_option: %d\n", recomp_get_config_double("number_option"));
    char* string_option = recomp_get_config_string("string_option");
    if (string_option != NULL) {
        recomp_printf("string_option: %s\n", string_option);
        recomp_free_config_string(string_option);
    }

    // Always spin attack.
    return true;
}

// Hook Play_UpdateMain to check if the L button is pressed and show this mod's UI if so.
RECOMP_HOOK("Play_UpdateMain") void on_play_update(PlayState* play) {
    if (CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_L)) {
        if (!context_shown) {
            recompui_show_context(context);
            context_shown = true;
        }
    }
}

