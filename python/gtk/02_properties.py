from gi.repository import Gtk

window = Gtk.Window()

label = Gtk.Label()
label.set_label("label is on fire")
label.set_angle(45)
label.set_halign(Gtk.Align.END)
window.add(label)

window.connect("delete-event", Gtk.main_quit)
window.show_all()
Gtk.main()
