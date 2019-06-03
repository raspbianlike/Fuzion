#pragma once

#include "types.h"

namespace panorama {
    //Menu UI Root - "CSGOMainMenu"
    //In-Game UI Root - "CSGOHud"
    struct PanelArraySlot {
        IUIPanel *panel;
        void *unk1;
        void *unk2;
        uint32_t someSymbol; // Might be a CPanoramaSymbol
        uint32_t boolean; // Looks to normally be 1, maybe IsVisible or IsFinishedSettingUp
    };
    struct PanelArray {
        void *_pad; // all F's
        uint32_t size; // I don't think this is right.
        uint32_t unk;
        //TODO: This array is not fixed-size! Something like: CUtlVector
        //Make sure to check panel pointer when using this!
        std::array<PanelArraySlot, 1024> slots;
    };

    // "CUIPanel::RemoveAndDeleteChildren" XREF to Function
    class IUIPanel {
    public:
        virtual void DESTROY1(void) = 0;

        virtual void DESTROY2(void) = 0;

        virtual void Initialize(IUIWindow *, IUIPanel *, const char *, unsigned int) = 0;

        virtual void InitClonedPanel(IUIPanel *other) = 0;

        virtual void RegisterEventHandlersOnPanel2DType(CPanoramaSymbol) = 0;

        virtual void Shutdown(void) = 0;

        virtual void FirePanelLoadedEvent(void) = 0;

        virtual void SetClientPtr(IUIPanelClient *) = 0;

        virtual IUIPanelClient *ClientPtr() = 0;

        virtual void SetID(const char *id) = 0;

        virtual const char *GetID(void) = 0; // ID in the XML, (EX: <Panel id="ShopCourierControls">)
        virtual void GetPanelType(void) = 0;

        virtual bool HasID() = 0;

        virtual void unk() = 0;

        virtual void unk2() = 0;

        virtual void unk3() = 0;

        virtual void unk4() = 0;

        virtual void unk5() = 0;

        virtual bool LoadLayout(const char *pathToXML, bool, bool) = 0;

        virtual bool LoadLayoutFromString(const char *layoutXML, bool, bool) = 0;

        virtual void LoadLayoutAsync(const char *pathToXML, bool, bool) = 0;

        virtual void LoadLayoutFromStringAsync(const char *layoutXML, bool, bool) = 0;

        virtual bool CreateChildren(const char *) = 0;

        virtual void UnloadLayout(void) = 0;

        virtual bool IsLoaded(void) = 0;

        virtual void SetParent(IUIPanel *parent) = 0;

        virtual IUIPanel *GetParent(void) = 0;

        virtual IUIWindow *GetParentWindow(void) = 0;

        virtual void SetVisible(bool state) = 0;

        virtual bool IsVisible(void) = 0;

        virtual bool IsTransparent(void) = 0;

        virtual void SetLayoutLoadedFromParent(IUIPanel *) = 0;

        virtual void SetPanelIntoContext(IUIPanel *) = 0;

        virtual void *GetLayoutFile(void) = 0;

        virtual void GetLayoutFileLoadedFrom(void) = 0;

        virtual int GetLayoutFileReloadCount(void) = 0;

        virtual void unk6() = 0;

        virtual void unk7() = 0;

        virtual void unk8() = 0;

        virtual IUIPanel *FindChild(const char *) = 0;

        virtual void unk9() = 0;

        virtual void FindChildTraverse(const char *) = 0;

        virtual void unk10() = 0;

        virtual IUIPanel *FindChildInLayoutFile(const char *) = 0;

        virtual void unk11() = 0;

        virtual IUIPanel *FindPanelInLayoutFile(const char *) = 0;

        virtual bool IsDecendantOf(IUIPanel const *const) = 0;

        virtual void RemoveAndDeleteChildren(void) = 0;

        virtual void RemoveAndDeleteChildrenOfType(CPanoramaSymbol) = 0;

        virtual int GetChildCount(void) = 0;

        virtual IUIPanel *GetChild(int) = 0;

        virtual IUIPanel *GetFirstChild(void) = 0;

        virtual IUIPanel *GetLastChild(void) = 0;

        virtual int GetChildIndex(IUIPanel const *const) = 0;

        virtual int GetChildCountOfType(CPanoramaSymbol) = 0;

        virtual int GetHiddenChildCount(void) = 0;

        virtual IUIPanel *GetHiddenChild(int) = 0;

        virtual IUIPanel *FindAncestor(const char *) = 0;

        virtual void sub_131D10() = 0; // new function, added around august 2018
        virtual void SetRepaint(EPanelRepaint) = 0;

        virtual void SetRepaintUpParentChain(void *unk) = 0;

        virtual bool ShouldDrawChildren(IUIPanel *) = 0;

        virtual void EnableBackgroundMovies(bool state) = 0;

        virtual void *AccessIUIStyle() = 0;

        virtual IUIPanelStyle *AccessIUIStyleDirty() = 0;

        virtual void ApplyStyles(bool apply) = 0;

        virtual void AfterStylesApplied(bool, EStyleRepaint, bool, bool) = 0;

        virtual void SetOnStylesChangedNeeded(void) = 0;

        virtual void *AccessChildren(void) = 0;

        virtual void DesiredLayoutSizeTraverse(float, float) = 0;

        virtual void DesiredLayoutSizeTraverse(float *, float *, float, float, bool) = 0;

        virtual void OnContentSizeTraverse(float *, float *, float, float, bool) = 0;

        virtual void LayoutTraverse(float, float, float, float) = 0;

        virtual void OnLayoutTraverse(float, float) = 0;

        virtual void SetPositionFromLayoutTraverse(CUILength, CUILength, CUILength) = 0;

        virtual void InvalidateSizeAndPosition(void) = 0;

        virtual void InvalidatePosition(void) = 0;

        virtual void SetActiveSizeAndPositionTransition(void) = 0;

        virtual void SetActivePositionTransition(void) = 0;

        virtual bool IsSizeValid(void) = 0;

        virtual bool IsPositionValid(void) = 0;

        virtual bool IsChildSizeValid(void) = 0;

        virtual bool IsChildPositionValid(void) = 0;

        virtual bool IsSizeTransitioning(void) = 0;

        virtual bool IsPositionTransitioning(void) = 0;

        virtual bool IsChildPositionTransitioning(void) = 0;

        virtual bool IsChildSizeTransitioning(void) = 0;

        virtual void TransitionPositionApplied(bool) = 0;

        virtual void sub_140EE0();

        virtual void sub_140F00();

        virtual float GetDesiredLayoutWidth(void) = 0; // these might be doubles, need to "double"-check
        virtual float GetDesiredLayoutHeight(void) = 0;

        virtual float GetContentWidth(void) = 0;

        virtual float GetContentHeight(void) = 0;

        virtual float GetActualLayoutWidth(void) = 0;

        virtual float GetActualLayoutHeight(void) = 0;

        virtual float GetActualRenderWidth(void) = 0;

        virtual float GetActualRenderHeight(void) = 0;

        virtual float GetActualXOffset(void) = 0;

        virtual float GetActualYOffset(void) = 0;

        virtual float GetRawActualXOffset(void) = 0;

        virtual float GetRawActualYOffset(void) = 0;

        virtual void unk12() = 0;

        virtual void sub_140FC0() = 0;

        virtual float GetContentsYScrollOffset(void) = 0;

        virtual float GetContentsXScrollOffset(void) = 0;

        virtual void unk_131A10() = 0;

        virtual void unk_152250() = 0;

        virtual void unk_152230() = 0;

        virtual void unk_1522A0() = 0;

        virtual void unk_152270() = 0;

        virtual void unk_1522D0() = 0;

        virtual void unk_1522F0() = 0;

        virtual void unk_152310() = 0;

        virtual void unk_152330() = 0;

        virtual void unk_152350() = 0;

        virtual void unk_152380() = 0;

        virtual void unk_131080() = 0;

        virtual void unk_1310F0() = 0;

        virtual void unk_134E50() = 0;

        virtual void unk_1350C0() = 0;

        virtual void unk_134EF0() = 0;

        virtual void unk_135450() = 0;

        virtual void unk_135470() = 0;

        virtual void unk_131710() = 0;

        virtual void unk_131760() = 0;

        virtual bool CanScrollUp(void) = 0;

        virtual bool CanScrollDown(void) = 0;

        virtual bool CanScrollLeft(void) = 0;

        virtual bool CanScrollRight(void) = 0;

        virtual void AddClass(const char *) = 0;

        virtual void AddClass(CPanoramaSymbol) = 0;

        virtual void AddClasses(CPanoramaSymbol *, unsigned int count) = 0;

        virtual void RemoveClass(const char *) = 0;

        virtual void RemoveClasses(CPanoramaSymbol const *const, unsigned int) = 0;

        virtual void RemoveClasses(const char *) = 0;

        virtual void RemoveAllClasses(void) = 0;

        virtual void sub_137540() = 0;

        virtual void *GetClasses(void) = 0;

        virtual bool HasClass(const char *) = 0;

        virtual bool HasClass(CPanoramaSymbol) = 0;

        virtual bool AscendantHasClass(const char *) = 0;

        virtual bool AscendantHasClass(CPanoramaSymbol) = 0;

        virtual void ToggleClass(const char *) = 0;

        virtual void ToggleClass(CPanoramaSymbol) = 0;

        virtual void SetHasClass(const char *, bool) = 0;

        virtual void SetHasClass(CPanoramaSymbol, bool) = 0;

        virtual void SwitchClass(const char *, const char *) = 0;

        virtual void SwitchClass(const char *, CPanoramaSymbol) = 0;

        virtual void unk_149DF0() = 0;

        virtual void unk_149D50() = 0;

        virtual void unk_149EB0() = 0;

        virtual void unk_149E50() = 0;

        virtual bool AcceptsInput() = 0;

        virtual void SetAcceptsInput(bool state) = 0;

        virtual bool AcceptsFocus() = 0;

        virtual void SetAcceptsFocus(bool state) = 0;

        virtual bool CanAcceptInput() = 0;

        virtual void SetDefaultFocus(const char *) = 0;

        virtual const char *GetDefaultFocus() = 0;

        virtual void SetDisableFocusOnMouseDown(bool state) = 0;

        virtual bool FocusOnMouseDown() = 0;

        virtual void unk_152460() = 0;

        virtual void unk_1523E0() = 0;

        virtual void unk_130E80() = 0;

        virtual void unk_130EB0() = 0;

        virtual void unk_152400() = 0;

        virtual void unk_152420() = 0;

        virtual void unk_152470() = 0;

        virtual void unk_152490() = 0;

        virtual void unk_1318C0() = 0;

        virtual void GetDefaultInputFocus(void) = 0;

        virtual void SetFocus(void) = 0;

        virtual void UpdateFocusInContext(void) = 0;

        virtual void SetFocusDueToHover(void) = 0;

        virtual void SetInputContextFocus(void) = 0;

        virtual unsigned long long GetStyleFlags(void) = 0;

        virtual void AddStyleFlag(EStyleFlags) = 0;

        virtual void RemoveStyleFlag(EStyleFlags) = 0;

        virtual bool IsInspected(void) = 0;

        virtual bool HasHoverStyle(bool) = 0;

        virtual void SetSelected(bool state) = 0;

        virtual bool IsSelected(void) = 0;

        virtual bool HasKeyFocus(void) = 0;

        virtual bool HasDescendantKeyFocus(void) = 0;

        virtual bool IsLayoutLoading(void) = 0;

        virtual void SetEnabled(bool state) = 0;

        virtual bool IsEnabled(void) = 0;

        virtual void unk_146920() = 0;

        virtual void unk_1525B0() = 0;

        virtual void unk13() = 0;

        virtual void sub_125010() = 0;

        virtual void SetAllChildrenActivationEnabled(bool state) = 0;

        virtual void SetHitTestEnabled(bool state) = 0;

        virtual bool HitTestEnabled(void) = 0;

        virtual void SetHitTestEnabledTraverse(bool state) = 0;

        virtual void unk_152630() = 0;

        virtual void unk_152660() = 0;

        virtual void SetDraggable(bool state) = 0;

        virtual bool IsDraggable(void) = 0;

        virtual void SetRememberChildFocus(bool state) = 0;

        virtual bool GetRememberChildFocus(void) = 0;

        virtual void ClearLastChildFocus(void) = 0;

        virtual void SetNeedsIntermediateTexture(bool state) = 0;

        virtual bool GetNeedsIntermediateTexture(void) = 0;

        virtual void unk_152DE0() = 0;

        virtual void unk_152E40() = 0;

        virtual void SetClipAfterTransform(bool state) = 0;

        virtual bool GetClipAfterTransform(void) = 0;

        virtual const char *GetInputNamespace(void) = 0;

        virtual void SetInputNamespace(const char *) = 0;

        virtual void MarkStylesDirty(bool state) = 0;

        virtual bool StylesDirty(void) = 0;

        virtual void sub_12A000() = 0;

        virtual bool ChildStylesDirty() = 0;

        virtual bool ParsePanelEvent(CPanoramaSymbol, const char *) = 0;

        virtual bool IsPanelEventSet(CPanoramaSymbol) = 0;

        virtual bool IsPanelEvent(CPanoramaSymbol) = 0;

        virtual void DispatchPanelEvent(CPanoramaSymbol) = 0;

        virtual void *GetJavaScriptContextParent(void) = 0;

        virtual void *UIImageManager(void) = 0;

        virtual void *UIRenderEngine(void) = 0;

        virtual void *unk_130DF0() = 0; // returns another class like the 2 above
        virtual void PaintTraverse(void) = 0;

        virtual void SetTabIndex(float) = 0;

        virtual float GetTabIndex(void) = 0;

        virtual void SetSelectionPosition(float, float) = 0;

        virtual void SetSelectionPositionX(float) = 0;

        virtual void SetSelectionPositionY(float) = 0;

        virtual float GetSelectionPositionX(void) = 0;

        virtual float GetSelectionPositionY(void) = 0;

        virtual float GetTabIndex_Raw(void) = 0;

        virtual float GetSelectionPositionX_Raw(void) = 0;

        virtual float GetSelectionPositionY_Raw(void) = 0;

        virtual void SetFocusToNextPanel(int, EFocusMoveDirection, bool, float, float, float, float, float) = 0;

        virtual void SetInputFocusToFirstOrLastChildInFocusOrder(EFocusMoveDirection, float, float) = 0;

        virtual void SelectionPosVerticalBoundary(void) = 0;

        virtual void SelectionPosHorizontalBoundary(void) = 0;

        virtual void SetChildFocusOnHover(bool state) = 0;

        virtual bool GetChildFocusOnHover(void) = 0;

        virtual void SetFocusOnHover(bool state) = 0;

        virtual bool GetFocusOnHover(void) = 0;

        virtual void ScrollToTop(void) = 0;

        virtual void ScrollToBottom(void) = 0;

        virtual void ScrollToLeftEdge(void) = 0;

        virtual void ScrollToRightEdge(void) = 0;

        virtual void ScrollParentToMakePanelFit(ScrollBehavior_t, bool) = 0;

        virtual void ScrollToFitRegion(float, float, float, float, ScrollBehavior_t, bool, bool) = 0;

        virtual bool CanSeeInParentScroll(void) = 0;

        virtual void OnScrollPositionChanged(void) = 0;

        virtual void SetSendChildScrolledIntoViewEvents(bool) = 0;

        virtual void OnCheckChildrenScrolledIntoView(void) = 0;

        virtual void FireScrolledIntoViewEvent(void) = 0;

        virtual void FireScrolledOutOfViewEvent(void) = 0;

        virtual bool IsScrolledIntoView(void) = 0;

        virtual void
        SortChildren() = 0; // (int (*)(panorama::IUIPanelClient * const*,panorama::IUIPanelClient * const*))
        virtual void AddChild(IUIPanel *) = 0;

        virtual void
        AddChildSorted() = 0; // (bool (*)(panorama::IUIPanelClient * const&,panorama::IUIPanelClient * const&),panorama::IUIPanel *)
        virtual void
        ResortChild() = 0; // (bool (*)(panorama::IUIPanelClient * const&,panorama::IUIPanelClient * const&),panorama::IUIPanel *)
        virtual void RemoveChild(IUIPanel *) = 0;

        virtual void unk_139310() = 0;

        virtual void unk_1393C0() = 0;

        virtual void unk_131260() = 0;

        virtual void unk_131270() = 0;

        virtual void SetMouseCanActivate(EMouseCanActivate, const char *) = 0;

        virtual EMouseCanActivate GetMouseCanActivate(void) = 0;

        virtual IUIPanel *FindParentForMouseCanActivate(void) = 0;

        virtual bool ReloadLayout(CPanoramaSymbol) = 0;

        virtual void ReloadStyleFileTraverse(CPanoramaSymbol) = 0;

        virtual bool HasOnActivateEvent(void) = 0;

        virtual bool HasOnMouseActivateEvent(void) = 0;

        virtual void SetupJavascriptObjectTemplate(void) = 0;

        virtual void SetLayoutFile(CPanoramaSymbol) = 0;

        virtual void
        BuildMatchingStyleList() = 0; // (CUtlVector<panorama::CascadeStyleFileInfo_t,CUtlMemory<panorama::CascadeStyleFileInfo_t,int>> *)
        virtual void GetAttribute(const char *, int) = 0;

        virtual void GetAttribute(const char *, const char *) = 0;

        virtual void unk_132680() = 0;

        virtual void GetAttribute(const char *, unsigned int) = 0;

        virtual void GetAttribute(const char *, unsigned long long) = 0;

        virtual void SetAttribute(const char *, int) = 0;

        virtual void SetAttribute(const char *, const char *) = 0;

        virtual void SetAttribute(const char *, unsigned int) = 0;

        virtual void SetAttribute(const char *, unsigned long long) = 0;

        virtual void SetAttribute() = 0;

        virtual void unk_132770() = 0;

        virtual void unk_132830() = 0;

        virtual void unk_132810() = 0;

        virtual void unk_1327C0() = 0;

        virtual void unk_132880() = 0;

        virtual void unk_13D2D0() = 0;

        virtual void unk_13D110() = 0;

        virtual void unk_13D350() = 0;

        virtual void unk_13D3D0() = 0;

        virtual void unk_13D450() = 0;

        virtual void unk_13D950() = 0;

        virtual void unk_13D870() = 0;

        virtual void unk_13D690() = 0;

        virtual void unk_13D420() = 0;

        virtual void SetAnimation(const char *, float, float, EAnimationTimingFunction, EAnimationDirection, float) = 0;

        virtual void UpdateVisibility(bool) = 0;

        virtual void unk14() = 0;

        virtual void SetProperty(CPanoramaSymbol, const char *) = 0;

        virtual void
        FindChildrenWithClass() = 0; // (char const*,CUtlVector<panorama::IUIPanel *,CUtlMemory<panorama::IUIPanel *,int>> &)
        virtual void
        FindChildrenWithClassTraverse() = 0; // (char const*,CUtlVector<panorama::IUIPanel *,CUtlMemory<panorama::IUIPanel *,int>> &)
        virtual void PlayFocusChangeSound(int, float) = 0;

        virtual void unk15() = 0;

        virtual void ClearPanelEvents(CPanoramaSymbol) = 0;

        virtual void SetPanelEvent(CPanoramaSymbol, IUIEvent *) = 0;

        virtual void
        SetPanelEvent2() = 0; // (panorama::CPanoramaSymbol,CUtlVector<panorama::IUIEvent *,CUtlMemory<panorama::IUIEvent *,int>> *)
        virtual bool GetAnalogStickScrollingEnabled(void) = 0;

        virtual void EnableAnalogStickScrolling(bool state) = 0;

        virtual void SetMouseTracking(bool state) = 0;

        virtual void SetInScrollbarConstruction(bool state) = 0;

        virtual void *GetVerticalScrollBar(void) = 0;

        virtual void *GetHorizontalScrollBar(void) = 0;

        virtual void GetPanelEvents(CPanoramaSymbol) = 0;

        virtual bool HasBeenLayedOut(void) = 0;

        virtual void OnStyleTransitionsCleanup(void) = 0;

        virtual void unk_1529D0() = 0;

        virtual void unk_1529F0() = 0;

        virtual void unk_152A00() = 0;

        virtual void unk_152A20() = 0;

        virtual void unk_136B20() = 0;

        virtual void unk_152A30() = 0;

        virtual void unk_139260() = 0;

        virtual void unk_1331A0() = 0;

        virtual void unk_1529A0() = 0;

        virtual void unk_1529B0() = 0;

        virtual void unk_1529C0() = 0;
    };
}
