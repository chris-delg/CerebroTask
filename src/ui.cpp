#include "../include/ui.hpp"

UI::UI() {
    login = new LoginPage();
    home = new HomePage();

    user_data = new UserBinData();
};

UI::~UI() {
    delete login;
    delete home;
    delete user_data;
};

void UI::changePage(int new_page) {
    if ((new_page < ui_size) && (new_page > -1)) { //curr_page should stay the same if not inbetween 0-ui_size
        curr_page = new_page;
    }
    return; 
};