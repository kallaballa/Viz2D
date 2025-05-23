# Display an Image {#v4d_display_image}

@prev_tutorial{v4d}
@next_tutorial{v4d_vector_graphics}

|    |    |
| -: | :- |
| Original author | Amir Hassan (kallaballa) <amir@viel-zu.org> |
| Compatibility | OpenCV >= 4.7 |

## Using the video pipeline
Actually there are two ways to display an image using V4D. The most convenient way is to use the video pipeline to feed an image to V4D. That has the advantage that the image is automatically resized (preserving aspect ratio) to framebuffer size and color converted (the framebuffer is BGRA).

@include samples/cpp/display_image.cpp

![The result](doc/display_image.png)

## Using direct framebuffer access
Instead of feeding to the video pipeline we can request the framebuffer in a ```fb``` context and copy the image to it. But first we must manually resize and color convert the image.

@include samples/cpp/display_image_fb.cpp

![The result](doc/display_image_fb.png)
