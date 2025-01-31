#include "modding.h"
#include "global.h"
#include "recompui.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));
RECOMP_IMPORT("*", u32 recomp_get_config_u32(const char* key));
RECOMP_IMPORT("*", double recomp_get_config_double(const char* key));
RECOMP_IMPORT("*", char* recomp_get_config_string(const char* key));
RECOMP_IMPORT("*", void recomp_free_config_string(char* str));

RecompuiContext context;
RecompuiResource root;
RecompuiResource outer_spacer1;
RecompuiResource outer_spacer2;
RecompuiResource inner_container;
RecompuiResource inner_spacer1;
RecompuiResource inner_spacer2;
RecompuiResource button;

bool context_shown = false;

RecompuiResource create_spacer(RecompuiContext context, RecompuiResource parent, float flex_grow, float flex_shrink, float flex_basis) {
    RecompuiResource ret = recompui_create_element(context, parent);

    recompui_set_flex_basis(ret, flex_basis, UNIT_DP);
    recompui_set_flex_grow(ret, flex_grow);
    recompui_set_flex_shrink(ret, flex_shrink);

    return ret;
}

RECOMP_CALLBACK("*", recomp_on_init)
void on_init() {
    context = recompui_create_context();

    recompui_open_context(context);

    root = recompui_context_root(context);

    // Split the root into 3 columns.
    outer_spacer1 = create_spacer(context, root, 1.0f, 0.0f, 0.0f);

    inner_container = recompui_create_element(context, root);
    recompui_set_display(inner_container, DISPLAY_FLEX);
    recompui_set_flex_direction(inner_container, FLEX_DIRECTION_COLUMN);

    outer_spacer2 = create_spacer(context, root, 1.0f, 0.0f, 0.0f);

    // Split the middle column up into 3 rows.
    inner_spacer1 = create_spacer(context, inner_container, 1.0f, 0.0f, 0.0f);

    button = recompui_create_button(context, inner_container, "Mod button", BUTTONSTYLE_PRIMARY);
    recompui_set_flex_grow(button, 0.0f);
    recompui_set_flex_shrink(button, 0.0f);
    recompui_set_flex_basis(button, 100.0f, UNIT_DP);
    recompui_set_width(button, 200.0f, UNIT_DP);
    
    inner_spacer2 = create_spacer(context, inner_container, 1.0f, 0.0f, 0.0f);

    recompui_close_context(context);
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

    if (context_shown) {
        recompui_hide_context(context);
    }
    else {
        recompui_show_context(context);
    }
    context_shown = !context_shown;

    // Always spin attack.
    return true;
}
