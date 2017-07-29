/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PyoAddSynthAudioProcessorEditor::PyoAddSynthAudioProcessorEditor (PyoAddSynthAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), valueTreeState (vts), processor (p),
      keyboardComponent (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    addAndMakeVisible (keyboardComponent);
    
    harm1Label.setText ("1st Harmonic", dontSendNotification);
    harm1Label.setJustificationType (Justification::centred);
    addAndMakeVisible (harm1Label);
    
    harm2Label.setText ("2nd Harmonic", dontSendNotification);
    harm2Label.setJustificationType (Justification::centred);
    addAndMakeVisible (harm2Label);
    
    harm3Label.setText ("3rd Harmonic", dontSendNotification);
    harm3Label.setJustificationType (Justification::centred);
    addAndMakeVisible (harm3Label);
    
    attackLabel.setText ("Attack", dontSendNotification);
    attackLabel.setJustificationType (Justification::centred);
    addAndMakeVisible (attackLabel);
    
    decayLabel.setText ("Decay", dontSendNotification);
    decayLabel.setJustificationType (Justification::centred);
    addAndMakeVisible (decayLabel);
    
    sustainLabel.setText ("Sustain", dontSendNotification);
    sustainLabel.setJustificationType (Justification::centred);
    addAndMakeVisible (sustainLabel);
    
    releaseLabel.setText ("Release", dontSendNotification);
    releaseLabel.setJustificationType (Justification::centred);
    addAndMakeVisible (releaseLabel);
    
    
    addAndMakeVisible (harm1Slider);
    harm1Attachment = new SliderAttachment (valueTreeState, "harm1", harm1Slider);
    
    addAndMakeVisible (harm2Slider);
    harm2Attachment = new SliderAttachment (valueTreeState, "harm2", harm2Slider);
    
    addAndMakeVisible (harm3Slider);
    harm3Attachment = new SliderAttachment (valueTreeState, "harm3", harm3Slider);
    
    
    addAndMakeVisible (attackSlider);
    attackAttachment = new SliderAttachment (valueTreeState, "attack", attackSlider);
    
    addAndMakeVisible (decaySlider);
    decayAttachment = new SliderAttachment (valueTreeState, "decay", decaySlider);
    
    addAndMakeVisible (sustainSlider);
    sustainAttachment = new SliderAttachment (valueTreeState, "sustain", sustainSlider);
    
    addAndMakeVisible (releaseSlider);
    releaseAttachment = new SliderAttachment (valueTreeState, "release", releaseSlider);
    
    setSize (400, 300);
}

PyoAddSynthAudioProcessorEditor::~PyoAddSynthAudioProcessorEditor()
{
}

//==============================================================================
void PyoAddSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    
}

void PyoAddSynthAudioProcessorEditor::resized()
{
    Rectangle<int> area (getLocalBounds());
    {
        keyboardComponent.setBounds (area.removeFromBottom (80).reduced(8));
        
        harm1Label.setBoundsRelative (0.05, 0.05, 0.2, 0.1);
        harm1Slider.setBoundsRelative (0.25, 0.05, 0.70, 0.1);
        
        harm2Label.setBoundsRelative (0.05, 0.15, 0.2, 0.1);
        harm2Slider.setBoundsRelative (0.25, 0.15, 0.70, 0.1);
        
        harm3Label.setBoundsRelative (0.05, 0.25, 0.2, 0.1);
        harm3Slider.setBoundsRelative (0.25, 0.25, 0.70, 0.1);
        
        attackLabel.setBoundsRelative (0.05, 0.35, 0.2, 0.1);
        attackSlider.setBoundsRelative (0.25, 0.35, 0.70, 0.1);
        
        decayLabel.setBoundsRelative (0.05, 0.45, 0.2, 0.1);
        decaySlider.setBoundsRelative (0.25, 0.45, 0.70, 0.1);
        
        sustainLabel.setBoundsRelative (0.05, 0.55, 0.2, 0.1);
        sustainSlider.setBoundsRelative (0.25, 0.55, 0.70, 0.1);
        
        releaseLabel.setBoundsRelative (0.05, 0.65, 0.2, 0.1);
        releaseSlider.setBoundsRelative (0.25, 0.65, 0.70, 0.1);
        
        
    }
}
