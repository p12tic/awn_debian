/* awn-panel-dispatcher.h generated by valac 0.10.4, the Vala compiler, do not modify */


#ifndef __AWN_PANEL_DISPATCHER_H__
#define __AWN_PANEL_DISPATCHER_H__

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <float.h>
#include <math.h>
#include "awn-panel.h"

G_BEGIN_DECLS


#define AWN_TYPE_IMAGE_STRUCT (awn_image_struct_get_type ())
typedef struct _AwnImageStruct AwnImageStruct;

#define AWN_TYPE_PANEL_DBUS_INTERFACE (awn_panel_dbus_interface_get_type ())
#define AWN_PANEL_DBUS_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), AWN_TYPE_PANEL_DBUS_INTERFACE, AwnPanelDBusInterface))
#define AWN_IS_PANEL_DBUS_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), AWN_TYPE_PANEL_DBUS_INTERFACE))
#define AWN_PANEL_DBUS_INTERFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), AWN_TYPE_PANEL_DBUS_INTERFACE, AwnPanelDBusInterfaceIface))

typedef struct _AwnPanelDBusInterface AwnPanelDBusInterface;
typedef struct _AwnPanelDBusInterfaceIface AwnPanelDBusInterfaceIface;

#define AWN_TYPE_PANEL_DISPATCHER (awn_panel_dispatcher_get_type ())
#define AWN_PANEL_DISPATCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), AWN_TYPE_PANEL_DISPATCHER, AwnPanelDispatcher))
#define AWN_PANEL_DISPATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), AWN_TYPE_PANEL_DISPATCHER, AwnPanelDispatcherClass))
#define AWN_IS_PANEL_DISPATCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), AWN_TYPE_PANEL_DISPATCHER))
#define AWN_IS_PANEL_DISPATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), AWN_TYPE_PANEL_DISPATCHER))
#define AWN_PANEL_DISPATCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), AWN_TYPE_PANEL_DISPATCHER, AwnPanelDispatcherClass))

typedef struct _AwnPanelDispatcher AwnPanelDispatcher;
typedef struct _AwnPanelDispatcherClass AwnPanelDispatcherClass;
typedef struct _AwnPanelDispatcherPrivate AwnPanelDispatcherPrivate;

struct _AwnImageStruct {
	gint width;
	gint height;
	gint rowstride;
	gboolean has_alpha;
	gint bits_per_sample;
	gint num_channels;
	gchar* pixel_data;
	gint pixel_data_length1;
};

struct _AwnPanelDBusInterfaceIface {
	GTypeInterface parent_iface;
	void (*add_applet) (AwnPanelDBusInterface* self, const char* desktop_file, GError** error);
	void (*delete_applet) (AwnPanelDBusInterface* self, const char* uid, GError** error);
	gint64 (*docklet_request) (AwnPanelDBusInterface* self, gint min_size, gboolean shrink, gboolean expand, GError** error);
	char** (*get_inhibitors) (AwnPanelDBusInterface* self, int* result_length1, GError** error);
	void (*get_snapshot) (AwnPanelDBusInterface* self, AwnImageStruct* result, GError** error);
	guint (*inhibit_autohide) (AwnPanelDBusInterface* self, const char* sender, const char* app_name, const char* reason, GError** error);
	void (*uninhibit_autohide) (AwnPanelDBusInterface* self, guint cookie, GError** error);
	void (*set_applet_flags) (AwnPanelDBusInterface* self, const char* uid, gint flags, GError** error);
	void (*set_glow) (AwnPanelDBusInterface* self, const char* sender, gboolean activate, GError** error);
	double (*get_offset_modifier) (AwnPanelDBusInterface* self);
	gint (*get_max_size) (AwnPanelDBusInterface* self);
	gint (*get_offset) (AwnPanelDBusInterface* self);
	void (*set_offset) (AwnPanelDBusInterface* self, gint value);
	gint (*get_path_type) (AwnPanelDBusInterface* self);
	gint (*get_position) (AwnPanelDBusInterface* self);
	void (*set_position) (AwnPanelDBusInterface* self, gint value);
	gint (*get_size) (AwnPanelDBusInterface* self);
	void (*set_size) (AwnPanelDBusInterface* self, gint value);
	gint64 (*get_panel_xid) (AwnPanelDBusInterface* self);
};

struct _AwnPanelDispatcher {
	GObject parent_instance;
	AwnPanelDispatcherPrivate * priv;
};

struct _AwnPanelDispatcherClass {
	GObjectClass parent_class;
};


GType awn_image_struct_get_type (void) G_GNUC_CONST;
AwnImageStruct* awn_image_struct_dup (const AwnImageStruct* self);
void awn_image_struct_free (AwnImageStruct* self);
void awn_image_struct_copy (const AwnImageStruct* self, AwnImageStruct* dest);
void awn_image_struct_destroy (AwnImageStruct* self);
AwnPanelDBusInterface* awn_panel_dbus_interface_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
GType awn_panel_dbus_interface_get_type (void) G_GNUC_CONST;
void awn_panel_dbus_interface_add_applet (AwnPanelDBusInterface* self, const char* desktop_file, GError** error);
void awn_panel_dbus_interface_delete_applet (AwnPanelDBusInterface* self, const char* uid, GError** error);
gint64 awn_panel_dbus_interface_docklet_request (AwnPanelDBusInterface* self, gint min_size, gboolean shrink, gboolean expand, GError** error);
char** awn_panel_dbus_interface_get_inhibitors (AwnPanelDBusInterface* self, int* result_length1, GError** error);
void awn_panel_dbus_interface_get_snapshot (AwnPanelDBusInterface* self, AwnImageStruct* result, GError** error);
guint awn_panel_dbus_interface_inhibit_autohide (AwnPanelDBusInterface* self, const char* sender, const char* app_name, const char* reason, GError** error);
void awn_panel_dbus_interface_uninhibit_autohide (AwnPanelDBusInterface* self, guint cookie, GError** error);
void awn_panel_dbus_interface_set_applet_flags (AwnPanelDBusInterface* self, const char* uid, gint flags, GError** error);
void awn_panel_dbus_interface_set_glow (AwnPanelDBusInterface* self, const char* sender, gboolean activate, GError** error);
double awn_panel_dbus_interface_get_offset_modifier (AwnPanelDBusInterface* self);
gint awn_panel_dbus_interface_get_max_size (AwnPanelDBusInterface* self);
gint awn_panel_dbus_interface_get_offset (AwnPanelDBusInterface* self);
void awn_panel_dbus_interface_set_offset (AwnPanelDBusInterface* self, gint value);
gint awn_panel_dbus_interface_get_path_type (AwnPanelDBusInterface* self);
gint awn_panel_dbus_interface_get_position (AwnPanelDBusInterface* self);
void awn_panel_dbus_interface_set_position (AwnPanelDBusInterface* self, gint value);
gint awn_panel_dbus_interface_get_size (AwnPanelDBusInterface* self);
void awn_panel_dbus_interface_set_size (AwnPanelDBusInterface* self, gint value);
gint64 awn_panel_dbus_interface_get_panel_xid (AwnPanelDBusInterface* self);
GType awn_panel_dispatcher_get_type (void) G_GNUC_CONST;
AwnPanelDispatcher* awn_panel_dispatcher_new (AwnPanel* panel);
AwnPanelDispatcher* awn_panel_dispatcher_construct (GType object_type, AwnPanel* panel);
AwnPanel* awn_panel_dispatcher_get_panel (AwnPanelDispatcher* self);


G_END_DECLS

#endif
