from gi.repository import Gtk


class MainWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="")

        # Boxes
        self.box = Gtk.Box(spacing=30)
        self.add(self.box)
        # Bacon Button
        self.bacon_button = Gtk.Button(label="Bacons")
        self.bacon_button.connect("clicked", self.clicked)
        self.box.pack_start(self.bacon_button, True, True, 0)
        # Tuna Button
        self.tuna_button = Gtk.Button(label="Tunas")
        self.tuna_button.connect("clicked", self.clicked)
        self.box.pack_start(self.tuna_button, True, True, 0)

    def clicked(self, widget):
        print("You clicked " + widget.get_label() + " button!")


window = MainWindow()
window.connect("delete-event", Gtk.main_quit)
window.show_all()
Gtk.main()
