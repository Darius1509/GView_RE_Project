#include "bashs.hpp"

using namespace GView::Type::BASHS;
using namespace AppCUI::Controls;

Panels::Information::Information(Reference<GView::Type::BASHS::BASHSFile> _bash) : TabPage("&Information")
{
    bash    = _bash;
    general = Factory::ListView::Create(this, "x:0,y:0,w:100%,h:10", { "n:Field,w:12", "n:Value,w:100" }, ListViewFlags::None);

    issues = Factory::ListView::Create(this, "x:0,y:21,w:100%,h:10", { "n:Info,w:200" }, ListViewFlags::HideColumns);

    this->Update();
}

void Panels::Information::UpdateGeneralInformation()
{
    LocalString<256> tempStr;
    NumericFormatter n;

    general->DeleteAllItems();
    general->AddItem("File");

    // Size
    general->AddItem({ "Size", tempStr.Format("%s bytes", n.ToString(bash->obj->GetData().GetSize(), { NumericFormatFlags::None, 10, 3, ',' }).data()) });
}

void Panels::Information::UpdateIssues()
{
    //placeholder
}

void Panels::Information::RecomputePanelsPositions()
{
    int w = this->GetWidth();
    int h = this->GetHeight();

    if ((!general.IsValid()) || (!issues.IsValid()))
        return;

    issues->SetVisible(false);
    this->general->Resize(w, h);
}

void Panels::Information::Update()
{
    UpdateGeneralInformation();
    UpdateIssues();
    RecomputePanelsPositions();
}
