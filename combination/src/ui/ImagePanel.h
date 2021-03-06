//
// Created by z on 19-4-27.
//

#ifndef SERVERGUI_MYIMGPANEL_H
#define SERVERGUI_MYIMGPANEL_H


#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/image.h>
#include <opencv2/opencv.hpp>


class ImagePanel : public wxPanel
{
    wxBitmap resized;
    int w, h;
    float c1 = 4.0 / 3.0;
    float c2 = 3.0 / 4.0;
    cv::Mat image_route;
    const int W = 2600, H = 2000;
    const double YMIN = -10000, YMAX = 10000;
    const double ZMIN = -6000, ZMAX = 20000;


public:
    wxImage image;


public:
    ImagePanel(wxFrame* parent);
    ImagePanel(wxFrame* parent, int c);

    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);

    wxImage wx_from_mat(cv::Mat &img);
    void mat2wxImage(cv::Mat &mat);


    void update(cv::Mat &CVImg);

    inline void yz2jk(double x, double y, int &j, int &k);

    void update(wxString file, wxBitmapType format);
private:
    DECLARE_EVENT_TABLE()
};

inline void ImagePanel::yz2jk(double y, double z, int &j, int &k) {
    j = static_cast<int>((YMAX - y) * H / (YMAX - YMIN));
    k = static_cast<int>((z - ZMIN) * W / (ZMAX - ZMIN));
}
#endif
