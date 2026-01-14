#include "bashs.hpp"

using namespace AppCUI;
using namespace AppCUI::Utils;
using namespace AppCUI::Application;
using namespace AppCUI::Controls;
using namespace GView::Utils;
using namespace GView::Type;
using namespace GView;
using namespace GView::View;

extern "C" {
PLUGIN_EXPORT bool Validate(const AppCUI::Utils::BufferView& buf, const std::string_view& extension)
{
    return true;
    // Check for .sh extension
    //if (extension == ".sh" || extension == ".bash")
    //    return true;

    // Check for shebang
    //if (buf.GetLength() >= 10) {
    //    if (buf[0] == '#' && buf[1] == '!') {
            // Check if it contains bash in first line (first 64 bytes should be enough)
    //        auto len = buf.GetLength() > 64 ? 64 : buf.GetLength();
    //        for (size_t i = 2; i < len - 3; i++) {
    //            if (buf[i] == 'b' && buf[i + 1] == 'a' && buf[i + 2] == 's' && buf[i + 3] == 'h')
    //                return true;
    //        }
    //    }
    //}

    //return false;
}

PLUGIN_EXPORT TypeInterface* CreateInstance()
{
    return new BASHS::BASHSFile();
}

PLUGIN_EXPORT bool PopulateWindow(Reference<WindowInterface> win)
{
    auto bash = win->GetObject()->GetContentType<BASHS::BASHSFile>();
    bash->Update();

    LexicalViewer::Settings settings;
    settings.SetParser(bash.ToObjectRef<LexicalViewer::ParseInterface>());
    win->CreateViewer(settings);

    win->CreateViewer<TextViewer::Settings>();

    View::BufferViewer::Settings s{};
    bash->selectionZoneInterface = win->GetSelectionZoneInterfaceFromViewerCreation(s);

    // add panels
    win->AddPanel(Pointer<TabPage>(new BASHS::Panels::Information(bash)), true);

    return true;
}

PLUGIN_EXPORT void UpdateSettings(IniSection sect)
{
    sect["Extension"]   = { "sh", "bash" };
    sect["Priority"]    = 1;
    sect["Pattern"]     = { "linestartswith:#!/bin/bash", "linestartswith:#!/usr/bin/env bash", "linestartswith:#!/bin/sh" };
    sect["Description"] = "Bash shell script file (*.sh, *.bash)";
}
}

int main()
{
    return 0;
}