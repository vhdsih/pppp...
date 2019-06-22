//
// Created by z on 19-4-26.
//

#ifndef SERVERGUI_MAINFRAME_H
#define SERVERGUI_MAINFRAME_H


#include <wx/wx.h>
#include <mutex>
#include <queue>
#include <thread>
#include <future>
#include <condition_variable>

#include "../constants.h"
#include "ImagePanel.h"
#include "wx/statline.h"


class MainFrame : public wxFrame {
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

    void OnStart(wxCommandEvent &event);
    void OnStop(wxCommandEvent &event);
    void OnPause(wxCommandEvent &event);
    void OnRecv(wxCommandEvent &event);
    void OnOutput(wxCommandEvent &event);
    void OnAutoMode(wxCommandEvent &event);
    void OnManualMode(wxCommandEvent &event);

    void ThreadUpdate(wxThreadEvent& event);

    void photo_update();
    void gnc_update();
    void load_data();

    void init_variables();
    void add_wins_into_sizer();

public:
    enum {
        Btn_Start,
        Btn_Pause,
        Btn_Stop,
        Btn_Recv,
        Btn_Output,
        Radio_Taking,
        Radio_Pausing,
    };
    cv::Mat mphoto;
    int nframe = 0;
    char gncinfo[512], photoinfo[128];
    wxString gncInfo;
    wxGauge *gauge;
    wxStaticText *gaugeTitle;
    bool dataLoad = true;
    bool image_frame_destroyed;
    double yy, zz;

    double roll, pitch, yaw;

    // photo gauge
    float ratio = 0;
    int line_nus = 0;

private:
    bool threadRunning = false, autoModeFlag = true;
    std::string output_path;

    wxPanel *panel;

    wxDirDialog *dir_dialog;

    wxTextCtrl *t_output_path, *t_error_rate, *t_rotate, *t_sun_direct;
    wxTextCtrl *t_roll, *t_pitch, *t_yaw;
    wxTextCtrl *t_error_roll, *t_error_pitch, *t_error_yaw;
    wxTextCtrl *t_start_i, *t_start_j, *t_ni, *t_nj;
    wxTextCtrl *t_expo;

    wxButton *btn_start, *btn_stop, *btn_pause, *btn_onece, *btn_output_path;
    wxButton *btn_change_cam_params;
    wxRadioButton *radio_taking, *radio_pausing;

    wxBoxSizer *rotate_sizer, *error_sizer, *sun_sizer;
    wxBoxSizer *sizer_all, *btn_sizer, *gnc_sizer, *camera_sizer, *output_sizer;
    wxBoxSizer *window_sizer, *expo_sizer, *camera_state_sizer;

    wxStaticText *gnc_title, *camera_title, *output_title;

    wxStaticText *rotate_title, *error_title, *sun_title;
    wxStaticText *yaw_title, *roll_title;
    wxStaticText *error_yaw_title, *error_roll_title;
    wxStaticText *open_win_title, *j_title, *ni_title, *nj_title;
    wxStaticText *expo_title;

    wxStaticLine* space_1, *space_2, *space_3, *space_4, *space_5;
    wxStaticLine* line_1, *line_2, *line_3, *line_4, *line_5;

private:
    DECLARE_EVENT_TABLE()
};

#endif //SERVERGUI_MAINFRAME_H