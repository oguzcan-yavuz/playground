from gi.repository import Gtk


class MainWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Title of window")

        self.button = Gtk.Button(label="Click here")
        self.button.connect("clicked", self.button_clicked)
        self.add(self.button)

    def button_clicked(self, widget):
        print("lol")


window = MainWindow()
window.connect("delete-event", Gtk.main_quit)
window.show_all()
Gtk.main()
