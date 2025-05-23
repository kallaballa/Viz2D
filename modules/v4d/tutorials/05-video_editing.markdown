# Video editing {#v4d_video_editing}

@prev_tutorial{v4d_font_rendering}
@next_tutorial{v4d_custom_source_and_sink}

|    |    |
| -: | :- |
| Original author | Amir Hassan (kallaballa) <amir@viel-zu.org> |
| Compatibility | OpenCV >= 4.7 |

## Render text on top of a video
Through adding a Source and a Sink v4d becomes capable of video editing. Reads a video, renders text on top and writes the result. Note: Reading and writing of video-data is multi-threaded in the background for performance reasons.

@include samples/cpp/video_editing.cpp

![The result](doc/video_editing.png)

