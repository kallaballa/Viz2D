// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
// Copyright Amir Hassan (kallaballa) <amir@viel-zu.org>

#ifndef SRC_OPENCV_V4D_DIALOG_HPP_
#define SRC_OPENCV_V4D_DIALOG_HPP_
#ifdef __EMSCRIPTEN__
#define V4D_USE_ES3 1
#endif

#ifndef V4D_USE_ES3
#define NANOGUI_USE_OPENGL
#else
#define NANOGUI_USE_GLES
#define NANOGUI_GLES_VERSION 3
#endif
#include <nanogui/nanogui.h>
#include <opencv2/core/cvdef.h>
#include <opencv2/core/mat.hpp>

#include <set>
#include <string>

namespace cv {
namespace viz {

using std::string;

/*!
 * A class for light-weight dialog (a dialog renderered inside a window) derived from nanogui::Window.
 * It keeps track of which dialogs are presented and which are lowered and is responsible for layout of lowered dialog-bars.
 */
class CV_EXPORTS Dialog: public nanogui::Window {
private:
    static std::function<bool(Dialog*, Dialog*)> v4dWin_Xcomparator;
    static std::set<Dialog*, decltype(v4dWin_Xcomparator)> all_windows_xsorted_;
    nanogui::Screen* screen_;
    nanogui::Vector2i lastDragPos_;
    nanogui::Vector2i maximizedPos_;
    nanogui::Button* minBtn_;
    nanogui::Button* maxBtn_;
    nanogui::ref<nanogui::AdvancedGridLayout> oldLayout_;
    nanogui::ref<nanogui::AdvancedGridLayout> newLayout_;
    bool minimized_ = false;
    bool mouse_drag_event(const nanogui::Vector2i& p, const nanogui::Vector2i& rel, int button,
            int mods) override;
public:
    /*!
     * Creates a Dialog.
     * @param screen The parent nanogui screen
     * @param x The x position of the dialog
     * @param y The y position of the dialog
     * @param title The title of the dialog
     */
    CV_EXPORTS Dialog(nanogui::Screen* screen, int x, int y, const string& title);
    /*!
     * Default destructor
     */
    CV_EXPORTS virtual ~Dialog();
    /*!
     * Checks if a dialog is minimized.
     * @return true if the dialog is minimized.
     */
    CV_EXPORTS bool isMinimized();
};

} /* namespace viz */
} /* namespace cv */

#endif /* SRC_OPENCV_V4D_DIALOG_HPP_ */
