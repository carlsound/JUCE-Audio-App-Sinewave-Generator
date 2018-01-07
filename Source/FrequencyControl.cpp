/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FrequencyControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FrequencyControl::FrequencyControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (frequencySlider = new Slider ("new slider"));
    frequencySlider->setRange (20, 20000, 10);
    frequencySlider->setValue(440, sendNotification);
    frequencyValue = 440.0;
    frequencySlider->setSliderStyle (Slider::LinearHorizontal);
    frequencySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    frequencySlider->addListener (this);

    addAndMakeVisible (frequencyLabel = new Label ("new label",
                                          TRANS("Frequency:")));
    frequencyLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    frequencyLabel->setJustificationType (Justification::centred);
    frequencyLabel->setEditable (false, false, false);
    frequencyLabel->setColour (TextEditor::textColourId, Colours::black);
    frequencyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 100);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FrequencyControl::~FrequencyControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    frequencySlider = nullptr;
    frequencyLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FrequencyControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FrequencyControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    frequencySlider->setBounds (8, 32, 296, 24);
    frequencyLabel->setBounds (88, 0, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FrequencyControl::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == frequencySlider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
        frequencyValue = static_cast<double>(frequencySlider->getValue());
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

double FrequencyControl::getFrequencyValue()
{
    return frequencyValue;
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FrequencyControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="150">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="new slider" id="81c17afa7ff12ab0" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="8 32 296 24" min="0" max="10" int="0"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="fff757dcf130d651" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="88 0 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
