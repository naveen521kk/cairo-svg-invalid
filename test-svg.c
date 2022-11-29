#include <cairo.h>
#include <cairo-svg.h>
#include <math.h>
#include <pango/pangocairo.h>

#define WIDTH 500
#define HEIGHT 500
#define TEXT "{ }"

int main(void)
{
    cairo_surface_t *surface;
    cairo_t *cr;
    PangoFontDescription *font_desc;
    PangoLayout *layout;
    double width_layout = WIDTH;
    double font_size_c = 20;
    PangoAttrList *pango_attr_list = pango_attr_list_new();
    const char *filename = "test.svg";

    surface = cairo_svg_surface_create(filename, WIDTH, HEIGHT);
    if (surface == NULL) {
        fprintf(stderr, "Error: cannot create surface\n");
        return 1;
    }
    cr = cairo_create(surface);
    if (cr == NULL) {
        fprintf(stderr, "Error: cannot create cairo context\n");
        return 1;
    }

    cairo_move_to(cr, 20, 20);

    layout = pango_cairo_create_layout(cr);
    if (layout == NULL){
        fprintf(stderr, "Error: cannot create pango layout\n");
        return 1;
    }

    pango_layout_set_width(layout, pango_units_from_double(width_layout));
    font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, pango_units_from_double(font_size_c));
    pango_font_description_set_family(font_desc, "Sans");
    pango_font_description_set_style(font_desc, PANGO_STYLE_ITALIC);
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_variant(font_desc, PANGO_VARIANT_NORMAL);
    pango_layout_set_font_description(layout, font_desc);

    pango_layout_set_text(layout, TEXT, -1);
    pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);
    pango_cairo_show_layout(cr, layout);

    g_object_unref(layout);
    pango_attr_list_unref(pango_attr_list);
    cairo_destroy(cr);

    cairo_surface_destroy(surface);

    return 0;
}