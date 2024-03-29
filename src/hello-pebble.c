#include <pebble.h>

Window *window;
TextLayer *text_layer;

void init() {
  // Create the Window
  window = window_create();

  // Push to the stack, animated
  window_stack_push(window, true);

  // Create the TextLayer, for display at (0, 0),
  // and with a size of 144 x 40
  text_layer = text_layer_create(GRect(0, 0, 144, 40));

  // Set the text that the TextLayer will display
  text_layer_set_text(text_layer, "Hello, Pebble!");

  // Add as child layer to be included in rendering
  layer_add_child(
    window_get_root_layer(window), 
    text_layer_get_layer(text_layer)
  );
}

void deinit() {
  // Destroy the Window
  window_destroy(window);

  // Destroy the TextLayer
  text_layer_destroy(text_layer);
}

int main(void) {
  // Initialize the app
  init();

  // Wait for app events
  app_event_loop();

  // Deinitialize the app
  deinit();

  // App finished without error
  return 0;
}
