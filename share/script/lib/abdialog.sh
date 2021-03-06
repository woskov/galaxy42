#!/bin/bash
# This code (in this file) is on BSD 2-clause license, (c) Copyrighted 2016 TiguSoft.pl
# abdialog - Any Bash Dialog
abdialog_ver=1

abdialog_curses=1 ; abdialog_gui=0 ;

function abdialog_check_program() {
	hash "$1" 2>/dev/null && echo 1 || echo 0
}

abdialog_program="whiptail" # default
# if possible change it:
if (( $(abdialog_check_program "dialog") == 1 )) ; then abdialog_program="dialog" ; fi 
# if [ -x "$(hash dialog &>/dev/null)" ] ; then abdialog_program="dialog" ; fi 

if [[ "$FORCE_DIALOG" == "whiptail" ]] ; then abdialog_program="whiptail" ; abdialog_curses=1 ; abdialog_gui=0 ; fi
if [[ "$FORCE_DIALOG" == "dialog" ]] ; then abdialog_program="dialog" ; abdialog_curses=1 ; abdialog_gui=0 ; fi

export abdialog_ver
export abdialog_curses
export abdialog_gui
export abdialog_program

function abdialog() {
	local argtab=()
	for arg in "$@" ; do
		local argfixed="${arg//$'\n'/\\n}";
		argtab+=("$argfixed")
	done
	$abdialog_program "${argtab[@]}"
}

function abdialog_exit() {
	clear
	if [[ ! -z "$1" ]] ; then
		exit "$1"
	else
		exit
	fi
}
function abdialog_info_quit_big() {
	[[ -z "$2" ]] || title="$2"
	local text="$1"
	abdialog --title "$title" \
		--yes-button "$(gettext "Ok")" --no-button "$(gettext "Quit")" \
		--yesno "$1" "$3" "$4" || abdialog_exit
}

function abdialog_info_quit() {
	title="Info"
	[[ -z "$2" ]] || title="$2"
	local text="$1"
	abdialog --title "$title" \
		--yes-button "$(gettext "Ok")" --no-button "$(gettext "Quit")" \
		--yesno "$1" 20 65 || abdialog_exit
}

function abdialog_info() {
	title="Info"
	[[ -z "$2" ]] || title="$2"
	local text="$1"
	abdialog --title "$title" \
		--yes-button "$(gettext "Ok")" \
		--msgbox "$1" 20 65 || abdialog_exit
}

function abdialog_fail() {
	title="Error"
	[[ -z "$2" ]] || title="$2"
	local text="$1"
	abdialog --title "$title" \
		--yes-button "$(gettext "Ok")" \
		--msgbox "$1" 20 65 || abdialog_exit
	abdialog_exit
}



