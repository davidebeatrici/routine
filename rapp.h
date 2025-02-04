// routine.c
// project sdk library
//
// Copyright (c) 2012-2021 Henry++

#pragma once

#include "routine.h"
#include "resource.h"

#include "rconfig.h"

// Structures
#if defined(APP_HAVE_SETTINGS)
typedef struct tagAPP_SETTINGS_PAGE
{
	HWND hwnd;
	UINT locale_id;
	INT dlg_id;
} APP_SETTINGS_PAGE, *PAPP_SETTINGS_PAGE;
#endif // APP_HAVE_SETTINGS

#if defined(APP_HAVE_UPDATES)
typedef struct tagAPP_UPDATE_COMPONENT
{
	PR_STRING full_name;
	PR_STRING short_name;
	PR_STRING version;
	PR_STRING new_version;
	PR_STRING temp_path;
	PR_STRING target_path;
	PR_STRING url;
	BOOLEAN is_installer;
	BOOLEAN is_haveupdate;
} APP_UPDATE_COMPONENT, *PAPP_UPDATE_COMPONENT;

typedef struct tagAPP_UPDATE_INFO
{
	PR_ARRAY components;
	HWND htaskdlg;
	HWND hparent;
	HANDLE hthread;
	BOOLEAN is_checking;
	BOOLEAN is_downloaded;
} APP_UPDATE_INFO, *PAPP_UPDATE_INFO;
#endif // APP_HAVE_UPDATES

typedef struct tagAPP_SHARED_IMAGE
{
	HINSTANCE hinst;
	HICON hicon;
	INT icon_id;
	INT icon_size;
} APP_SHARED_IMAGE, *PAPP_SHARED_IMAGE;

// Enums
typedef enum tagLOG_LEVEL
{
	LOG_LEVEL_DEBUG = 1,
	LOG_LEVEL_INFO = 2,
	LOG_LEVEL_WARNING = 3,
	LOG_LEVEL_ERROR = 4,
	LOG_LEVEL_CRITICAL = 5,
} LOG_LEVEL, *PLOG_LEVEL;

// Global variables
#if !defined(APP_CONSOLE)
static HWND app_hwnd = NULL;
#endif // !APP_CONSOLE

#if defined(APP_HAVE_SETTINGS)
static HWND app_settings_hwnd = NULL;
#endif // APP_HAVE_SETTINGS

/*
	Configuration
*/

VOID _r_config_initialize ();

BOOLEAN _r_config_getbooleanex (_In_ LPCWSTR key_name, _In_ BOOLEAN def_value, _In_opt_ LPCWSTR section_name);
INT _r_config_getintegerex (_In_ LPCWSTR key_name, _In_ INT def_value, _In_opt_ LPCWSTR section_name);
UINT _r_config_getuintegerex (_In_ LPCWSTR key_name, UINT def_value, _In_opt_ LPCWSTR section_name);
LONG _r_config_getlongex (_In_ LPCWSTR key_name, LONG def_value, _In_opt_ LPCWSTR section_name);
LONG64 _r_config_getlong64ex (_In_ LPCWSTR key_name, LONG64 def_value, _In_opt_ LPCWSTR section_name);
ULONG _r_config_getulongex (_In_ LPCWSTR key_name, ULONG def_value, _In_opt_ LPCWSTR section_name);
ULONG64 _r_config_getulong64ex (_In_ LPCWSTR key_name, _In_ ULONG64 def_value, _In_opt_ LPCWSTR section_name);
VOID _r_config_getfont (_In_ LPCWSTR key_name, _In_ HWND hwnd, _Inout_ PLOGFONT logfont, _In_opt_ LPCWSTR section_name);
BOOLEAN _r_config_getsize (_In_ LPCWSTR key_name, _Out_ PSIZE size, _In_ PSIZE def_value, _In_opt_ LPCWSTR section_name);
PR_STRING _r_config_getstringexpandex (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR def_value, _In_opt_ LPCWSTR section_name);
LPCWSTR _r_config_getstringex (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR def_value, _In_opt_ LPCWSTR section_name);

FORCEINLINE BOOLEAN _r_config_getboolean (_In_ LPCWSTR key_name, _In_ BOOLEAN def_value)
{
	return _r_config_getbooleanex (key_name, def_value, NULL);
}

FORCEINLINE INT _r_config_getinteger (_In_ LPCWSTR key_name, _In_ INT def_value)
{
	return _r_config_getintegerex (key_name, def_value, NULL);
}

FORCEINLINE UINT _r_config_getuinteger (_In_ LPCWSTR key_name, _In_ UINT def_value)
{
	return _r_config_getuintegerex (key_name, def_value, NULL);
}

FORCEINLINE LONG _r_config_getlong (_In_ LPCWSTR key_name, _In_ LONG def_value)
{
	return _r_config_getlongex (key_name, def_value, NULL);
}

FORCEINLINE LONG64 _r_config_getlong64 (_In_ LPCWSTR key_name, _In_ LONG64 def_value)
{
	return _r_config_getlong64ex (key_name, def_value, NULL);
}

FORCEINLINE ULONG _r_config_getulong (_In_ LPCWSTR key_name, _In_ ULONG def_value)
{
	return _r_config_getulongex (key_name, def_value, NULL);
}

FORCEINLINE ULONG64 _r_config_getulong64 (_In_ LPCWSTR key_name, _In_ ULONG64 def_value)
{
	return _r_config_getulong64ex (key_name, def_value, NULL);
}

FORCEINLINE PR_STRING _r_config_getstringexpand (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR def_value)
{
	return _r_config_getstringexpandex (key_name, def_value, NULL);
}

FORCEINLINE LPCWSTR _r_config_getstring (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR def_value)
{
	return _r_config_getstringex (key_name, def_value, NULL);
}

VOID _r_config_setbooleanex (_In_ LPCWSTR key_name, _In_ BOOLEAN value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setintegerex (_In_ LPCWSTR key_name, _In_ INT value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setuintegerex (_In_ LPCWSTR key_name, _In_ UINT value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setlongex (_In_ LPCWSTR key_name, _In_ LONG value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setlong64ex (_In_ LPCWSTR key_name, _In_ LONG64 value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setulongex (_In_ LPCWSTR key_name, _In_ ULONG value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setulong64ex (_In_ LPCWSTR key_name, _In_ ULONG64 value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setfont (_In_ LPCWSTR key_name, _In_ HWND hwnd, _In_ PLOGFONT logfont, _In_opt_ LPCWSTR section_name);
VOID _r_config_setsize (_In_ LPCWSTR key_name, _In_ PSIZE size, _In_opt_ LPCWSTR section_name);
VOID _r_config_setstringexpandex (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR value, _In_opt_ LPCWSTR section_name);
VOID _r_config_setstringex (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR value, _In_opt_ LPCWSTR section_name);

FORCEINLINE VOID _r_config_setboolean (_In_ LPCWSTR key_name, _In_ BOOLEAN value)
{
	_r_config_setbooleanex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setinteger (_In_ LPCWSTR key_name, _In_ INT value)
{
	_r_config_setintegerex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setuinteger (_In_ LPCWSTR key_name, _In_ UINT value)
{
	_r_config_setuintegerex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setlong (_In_ LPCWSTR key_name, _In_ LONG value)
{
	_r_config_setlongex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setlong64 (_In_ LPCWSTR key_name, _In_ LONG64 value)
{
	_r_config_setlong64ex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setulong (_In_ LPCWSTR key_name, _In_ ULONG value)
{
	_r_config_setulongex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setulong64 (_In_ LPCWSTR key_name, _In_ ULONG64 value)
{
	_r_config_setulong64ex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setstringexpand (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR value)
{
	_r_config_setstringexpandex (key_name, value, NULL);
}

FORCEINLINE VOID _r_config_setstring (_In_ LPCWSTR key_name, _In_opt_ LPCWSTR value)
{
	_r_config_setstringex (key_name, value, NULL);
}

/*
	Localization
*/

#if !defined(APP_CONSOLE)
VOID _r_locale_initialize ();

#if defined(APP_HAVE_SETTINGS)
VOID _r_locale_applyfromcontrol (_In_ HWND hwnd, _In_ INT ctrl_id);
#endif // !APP_HAVE_SETTINGS

VOID _r_locale_applyfrommenu (_In_ HMENU hmenu, _In_ UINT selected_id);
VOID _r_locale_enum (_In_ PVOID hwnd, _In_ INT ctrl_id, _In_opt_ UINT menu_id);

SIZE_T _r_locale_getcount ();
LPCWSTR _r_locale_getstring (_In_ UINT uid);
LONG64 _r_locale_getversion ();
#endif // !APP_CONSOLE

/*
	Settings window
*/

#if defined(APP_HAVE_SETTINGS)
VOID _r_settings_addpage (_In_ INT dlg_id, _In_ UINT locale_id);
VOID _r_settings_adjustchild (_In_ HWND hwnd, _In_ INT ctrl_id, _In_ HWND hchild);
VOID _r_settings_createwindow (_In_ HWND hwnd, _In_opt_ DLGPROC dlg_proc, _In_opt_ INT dlg_id);
INT_PTR CALLBACK _r_settings_wndproc (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

FORCEINLINE HWND _r_settings_getwindow ()
{
	return app_settings_hwnd;
}
#endif // APP_HAVE_SETTINGS

/*
	Autorun (optional feature)
*/

#if defined(APP_HAVE_AUTORUN)
BOOLEAN _r_autorun_isenabled ();
BOOLEAN _r_autorun_enable (_In_opt_ HWND hwnd, _In_ BOOLEAN is_enable);
#endif // APP_HAVE_AUTORUN

/*
	Skip UAC (optional feature)
*/

#if defined(APP_HAVE_SKIPUAC)
BOOLEAN _r_skipuac_isenabled ();
HRESULT _r_skipuac_enable (_In_opt_ HWND hwnd, _In_ BOOLEAN is_enable);
BOOLEAN _r_skipuac_run ();
#endif // APP_HAVE_SKIPUAC

/*
	Update checker (optional feature)
*/

#if defined(APP_HAVE_UPDATES)
VOID _r_update_addcomponent (_In_opt_ LPCWSTR full_name, _In_opt_ LPCWSTR short_name, _In_opt_ LPCWSTR version, _In_opt_ LPCWSTR target_path, _In_ BOOLEAN is_installer);
VOID _r_update_check (_In_opt_ HWND hparent);
THREAD_API _r_update_checkthread (PVOID lparam);

BOOLEAN NTAPI _r_update_downloadcallback (ULONG total_written, ULONG total_length, PVOID pdata);
THREAD_API _r_update_downloadthread (PVOID lparam);

HRESULT CALLBACK _r_update_pagecallback (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, LONG_PTR pdata);
INT _r_update_pagenavigate (_In_opt_ HWND htaskdlg, _In_opt_ LPCWSTR main_icon, _In_ TASKDIALOG_FLAGS flags, _In_ TASKDIALOG_COMMON_BUTTON_FLAGS buttons, _In_opt_ LPCWSTR main, _In_opt_ LPCWSTR content, _In_opt_ LONG_PTR lpdata);

VOID _r_update_install (_In_ LPCWSTR install_path);

#endif // APP_HAVE_UPDATES

VOID _r_log (_In_ LOG_LEVEL log_level, _In_ UINT tray_id, _In_ LPCWSTR fn, _In_ ULONG code, _In_opt_ LPCWSTR description);
VOID _r_log_v (_In_ LOG_LEVEL log_level, _In_ UINT tray_id, _In_ LPCWSTR fn, _In_ ULONG code, _In_ LPCWSTR format, ...);

#if !defined(APP_CONSOLE)
VOID _r_show_aboutmessage (_In_opt_ HWND hwnd);
VOID _r_show_errormessage (_In_opt_ HWND hwnd, _In_opt_ LPCWSTR main, _In_ ULONG error_code, _In_opt_ LPCWSTR description, _In_opt_ HINSTANCE hmodule);
BOOLEAN _r_show_confirmmessage (_In_opt_ HWND hwnd, _In_opt_ LPCWSTR main, _In_ LPCWSTR text, _In_opt_ LPCWSTR config_key);
INT _r_show_message (_In_opt_ HWND hwnd, _In_ ULONG flags, _In_opt_ LPCWSTR title, _In_opt_ LPCWSTR main, _In_ LPCWSTR content);

VOID _r_window_restoreposition (_In_ HWND hwnd, _In_ LPCWSTR window_name);
VOID _r_window_saveposition (_In_ HWND hwnd, _In_ LPCWSTR window_name);

#endif // APP_CONSOLE

/*
	Application
*/

BOOLEAN _r_app_initialize ();

LPCWSTR _r_app_getdirectory ();
LPCWSTR _r_app_getconfigpath ();

#if !defined(APP_CONSOLE)
LPCWSTR _r_app_getlocalepath ();
#endif // !APP_CONSOLE

LPCWSTR _r_app_getlogpath ();
LPCWSTR _r_app_getprofiledirectory ();
LPCWSTR _r_app_getuseragent ();

#if !defined(APP_CONSOLE)
BOOLEAN _r_app_createwindow (_In_ INT dlg_id, _In_opt_ INT icon_id, _In_opt_ DLGPROC dlg_proc);

_Ret_maybenull_
HICON _r_app_getsharedimage (_In_opt_ HINSTANCE hinst, _In_ INT icon_id, _In_ INT icon_size);

BOOLEAN _r_app_runasadmin ();
VOID _r_app_restart (_In_opt_ HWND hwnd);
#endif // !APP_CONSOLE

FORCEINLINE LPCWSTR _r_app_getname ()
{
	return APP_NAME;
}

FORCEINLINE LPCWSTR _r_app_getnameshort ()
{
	return APP_NAME_SHORT;
}

FORCEINLINE LPCWSTR _r_app_getauthor ()
{
	return APP_AUTHOR;
}

FORCEINLINE LPCWSTR _r_app_getcopyright ()
{
	return APP_COPYRIGHT;
}

FORCEINLINE LPCWSTR _r_app_getdonate_url ()
{
	return L"https://www.henrypp.org/donate?from=" APP_NAME_SHORT;
}

FORCEINLINE LPCWSTR _r_app_getsources_url ()
{
	return L"https://github.com/henrypp";
}

FORCEINLINE LPCWSTR _r_app_getwebsite_url ()
{
	return L"https://www.henrypp.org";
}

FORCEINLINE LPCWSTR _r_app_getversiontype ()
{
#if defined(_DEBUG) || defined(APP_BETA)
	return L"Pre-release";
#else
	return L"Release";
#endif // _DEBUG || APP_BETA
}

FORCEINLINE INT _r_app_getarch ()
{
#ifdef _WIN64
	return 64;
#else
	return 32;
#endif // _WIN64
}

FORCEINLINE LPCWSTR _r_app_getversion ()
{
	return APP_VERSION;
}

#if !defined(APP_CONSOLE)
FORCEINLINE HWND _r_app_gethwnd ()
{
	return app_hwnd;
}
#endif // !APP_CONSOLE

#if !defined(APP_CONSOLE)
FORCEINLINE BOOLEAN _r_app_isclassicui ()
{
	return !IsAppThemed () || _r_config_getboolean (L"ClassicUI", APP_CLASSICUI);
}
#endif // !APP_CONSOLE
