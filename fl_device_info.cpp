#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

#include <fstream>
#include <sstream>

// Global text buffer
Fl_Text_Buffer *textbuf;

// CPU bilgisi oku (/proc/cpuinfo)
std::string get_cpu_info() {
    std::ifstream file("/proc/cpuinfo");
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Ortak callback (menu + buton)
void show_info_cb(Fl_Widget*, void*) {
    std::string info = get_cpu_info();
    textbuf->text(info.c_str());
}

void clear_cb(Fl_Widget*, void*) {
    textbuf->text("");  // text alanını temizler
}

int main() {
    Fl_Window *win = new Fl_Window(600, 400, "Sistem Bilgisi");
    win->resizable(win);
    // Menü
    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, 600, 25);
    menu->add("Sistem/Bilgi", 0, show_info_cb);

    // Üstte text display
    Fl_Text_Display *display = new Fl_Text_Display(10, 35, 580, 280);
    textbuf = new Fl_Text_Buffer();
    display->buffer(textbuf);

    // Altta yatay buton alanı (group gibi)
    Fl_Group *bottom = new Fl_Group(10, 320, 580, 70);
    Fl_Button *btn = new Fl_Button(10, 330, 120, 40, "Donanım Bilgisi");
    btn->callback(show_info_cb);
    Fl_Button *clearBtn = new Fl_Button(140, 330, 120, 40, "Temizle");
clearBtn->callback(clear_cb);

    bottom->end();

    win->end();
    win->show();

    return Fl::run();
}
