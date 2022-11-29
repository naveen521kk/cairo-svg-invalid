#include <cairo.h>
#include <cairo-svg.h>
#include <math.h>
#include <pango/pangocairo.h>

#define WIDTH 500
#define HEIGHT 500
#define TEXT " "

int main(void)
{
    cairo_surface_t *surface;
    cairo_t *cr;
    PangoLayout *layout;
    double width_layout = WIDTH;
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

    pango_layout_set_text(layout, TEXT, -1);
    pango_cairo_show_layout(cr, layout);

    g_object_unref(layout);
    cairo_destroy(cr);

    cairo_surface_destroy(surface);

    return 0;
}