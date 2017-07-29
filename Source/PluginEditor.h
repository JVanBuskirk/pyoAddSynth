/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class PyoAddSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:

    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    PyoAddSynthAudioProcessorEditor (PyoAddSynthAudioProcessor&, AudioProcessorValueTreeState&);
    ~PyoAddSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    AudioProcessorValueTreeState& valueTreeState;
    
    Label harm1Label;
    Label harm2Label;
    Label harm3Label;
    
    Label attackLabel;
    Label decayLabel;
    Label sustainLabel;
    Label releaseLabel;
    
    Slider harm1Slider;
    Slider harm2Slider;
    Slider harm3Slider;
    
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;
    
    ScopedPointer<SliderAttachment> harm1Attachment;
    ScopedPointer<SliderAttachment> harm2Attachment;
    ScopedPointer<SliderAttachment> harm3Attachment;
    
    ScopedPointer<SliderAttachment> attackAttachment;
    ScopedPointer<SliderAttachment> decayAttachment;
    ScopedPointer<SliderAttachment> sustainAttachment;
    ScopedPointer<SliderAttachment> releaseAttachment;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PyoAddSynthAudioProcessor& processor;
    MidiKeyboardComponent keyboardComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PyoAddSynthAudioProcessorEditor)
};
