/*
 *  This file is part of RawTherapee.
 */
#ifndef _COLORTONING_H_
#define _COLORTONING_H_

#include <gtkmm.h>
#include "adjuster.h"
#include "toolpanel.h"
#include "guiutils.h"
#include "curveeditor.h"
#include "curveeditorgroup.h"
#include "thresholdadjuster.h"
#include "colorprovider.h"

class ColorToning : public ToolParamBlock, public FoldableToolPanel,  public rtengine::AutoColorTonListener,public CurveListener, public ColorProvider,
                    public ThresholdAdjusterListener, public AdjusterListener {

  protected:
    Gtk::CheckButton* enabled;
    //Gtk::HSeparator* splitSep;
    Gtk::HSeparator* satLimiterSep;
    Gtk::HSeparator* colorSep;
    CurveEditorGroup* colorCurveEditorG;
    CurveEditorGroup* opacityCurveEditorG;
    CurveEditorGroup* clCurveEditorG;
    CurveEditorGroup* cl2CurveEditorG;
    FlatCurveEditor* opacityShape;
    FlatCurveEditor* colorShape;
    DiagonalCurveEditor* clshape;
    DiagonalCurveEditor* cl2shape;
    Gtk::HBox* ctbox;
	
    Gtk::VBox* chanMixerBox;
    MyComboBoxText* method;
    sigc::connection methodconn;
    MyComboBoxText* twocolor;
    Adjuster* redlow;
    Adjuster* greenlow;
    Adjuster* bluelow;
    Adjuster* redmed;
    Adjuster* greenmed;
    Adjuster* bluemed;
    Adjuster* redhigh;
    Adjuster* greenhigh;
    Adjuster* bluehigh;
    Adjuster* balance;
    //Adjuster* satlow;
    //Adjuster* sathigh;
    Gtk::CheckButton* autosat;
    ThresholdAdjuster* shadowsColSat;
    ThresholdAdjuster* hlColSat;
    Adjuster* satProtectionThreshold;
    Adjuster* saturatedOpacity;
	Adjuster* strengthprotection;
	Gtk::Image* itot;
	Gtk::Image* iby;
	Gtk::Image* irg;
	
    Gtk::Button* neutral;
    Gtk::Button* neutralcur;
    Gtk::HBox* neutrHBox;
    Gtk::HBox* neutrcurHBox;
    Gtk::HBox* chromaHbox;
    Gtk::Label* colLabel;
    Gtk::Label* interLabel;
    Gtk::Label* chroLabel;
	int nextbw;
	int nextsatth;
	int nextsatpr;
	Glib::ustring labchroma1;
	Glib::ustring labchroma2;
	Glib::ustring nextbalcolor;
	Glib::ustring balcolor;	
    bool lastEnabled;
    sigc::connection enaConn;
    bool lasttwocolor;
    sigc::connection neutralconn, twocconn, neutralcurconn;
    bool lastautosat;
    sigc::connection autosatConn;

    Gtk::CheckButton* lumamode;
    bool lastLumamode;
    sigc::connection lumamodeConn;

  public:
    ColorToning ();
    ~ColorToning();
    void read                (const rtengine::procparams::ProcParams* pp, const ParamsEdited* pedited=NULL);
    void write               (rtengine::procparams::ProcParams* pp, ParamsEdited* pedited=NULL);
    void setBatchMode        (bool batchMode);
    void setDefaults         (const rtengine::procparams::ProcParams* defParams, const ParamsEdited* pedited=NULL);
    void trimValues          (rtengine::procparams::ProcParams* pp);
    void adjusterChanged     (Adjuster* a, double newval);
    void adjusterChanged     (ThresholdAdjuster* a, double newBottom, double newTop);
    void setAdjusterBehavior (bool splitAdd, bool satThresholdAdd, bool satOpacityAdd, bool strprotectAdd, bool balanceAdd);
    void neutral_pressed     ();
    void neutralcur_pressed  ();
	void autoColorTonChanged (int bwct, int satthres, int satprot);
	bool CTComp_         ();

    void enabledChanged      ();
    void curveChanged        (CurveEditor* ce);
    void autosatChanged      ();
    void autoOpenCurve       ();
    void methodChanged       ();
    void twocolorChanged     (bool changedbymethod);
    void twoColorChangedByGui();
    void lumamodeChanged     ();

    void colorForValue       (double valX, double valY, enum ColorCaller::ElemType elemType, int callerId, ColorCaller* caller);
};

#endif