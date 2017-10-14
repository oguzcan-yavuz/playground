from gi.repository import Gtk
import sqlite3


class MainWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Main Window")
        self.set_border_width(20)
        listbox = Gtk.ListBox()
        listbox.set_selection_mode(Gtk.SelectionMode.NONE)
        self.add(listbox)

        # Text Areas
        row_1 = Gtk.ListBoxRow()
        name_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=100)
        row_1.add(name_box)
        name_label = Gtk.Label("Issue Name: ")
        self.issue_name = Gtk.Entry()
        name_box.pack_start(name_label, True, True, 0)
        name_box.pack_start(self.issue_name, True, True, 0)
        listbox.add(row_1)

        row_2 = Gtk.ListBoxRow()
        product_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=100)
        row_2.add(product_box)
        product_label = Gtk.Label("Product Name: ")
        self.issue_product = Gtk.Entry()
        product_box.pack_start(product_label, True, True, 0)
        product_box.pack_start(self.issue_product, True, True, 0)
        listbox.add(row_2)

        row_3 = Gtk.ListBoxRow()
        solved_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=100)
        row_3.add(solved_box)
        solved_label = Gtk.Label("Is solved?: ")
        self.issue_solved = Gtk.CheckButton()
        solved_box.pack_start(solved_label, True, True, 0)
        solved_box.pack_start(self.issue_solved, True, True, 0)
        listbox.add(row_3)

        # Buttons
        create_button = Gtk.Button(label="Create new issue")
        create_button.connect("clicked", self.create_issue)
        listbox.add(create_button)

    def create_issue(self, widget):
        name_value = self.issue_name.get_text()
        product_value = self.issue_product.get_text()
        solved_value = self.issue_solved.get_active()
        self.issue_name.set_text("")
        self.issue_product.set_text("")
        self.issue_solved.set_active(0)

        cur.execute("INSERT INTO issues VALUES (?, ?, CURRENT_TIMESTAMP, ?)", (name_value, product_value, solved_value))
        con.commit()


con = sqlite3.connect('test.db')
cur = con.cursor()

handlers = {
    con.close: Gtk.main_quit
}

builder = Gtk.Builder()
builder.connect_signals(handlers)

window = MainWindow()
window.connect("delete-event", Gtk.main_quit)
window.show_all()
Gtk.main()

# cur.execute("CREATE TABLE issues (name TEXT, product TEXT, creation_time TEXT, solved INT);")
# con.close()
