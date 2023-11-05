#include <iostream>

#include <wx/wx.h>

class MyApp : public wxApp
{
    public:
        bool OnInit() override;

};

wxIMPLEMENT_APP(MyApp);

class Frame : public wxFrame
{
    public:
        Frame();

    private:
};

enum Events
{
event_hello = 1
};

Frame::Frame()
    : wxFrame(nullptr, wxID_ANY, "Hello!")
{
    auto *menu_file = new wxMenu;
    menu_file->Append(Events::event_hello, "&Hello....\tCTRL+H",
                      "Help string shown for this thing");
    menu_file->AppendSeparator();
    menu_file->Append(wxID_EXIT);

    auto *menu_help = new wxMenu;
    menu_help->Append(wxID_ABOUT);

    auto *menu_bar = new wxMenuBar;
    menu_bar->Append(menu_file, "&File");
    menu_bar->Append(menu_help, "&Help");

    SetMenuBar(menu_bar);

    CreateStatusBar();
    SetStatusText("Hello there!");

    Bind(wxEVT_MENU, [=](wxCommandEvent&){
        wxLogMessage("Hello from Hello");
    }, Events::event_hello);

    Bind(wxEVT_MENU, [=](wxCommandEvent&){
        wxMessageBox("This is a wxWidgets Hello World example",
                     "About Hello World", wxOK | wxICON_INFORMATION);
    }, wxID_ABOUT);

    Bind(wxEVT_MENU, [=](wxCommandEvent&){
        Close(1);
    }, wxID_EXIT);
}


bool MyApp::OnInit()
{
    auto *frame = new Frame();

    frame->Show();


    return true;
}
