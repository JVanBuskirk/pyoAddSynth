/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PyoAddSynthAudioProcessor::PyoAddSynthAudioProcessor():
#ifndef JucePlugin_PreferredChannelConfigurations
    AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    parameters (*this, nullptr)
{
    parameters.createAndAddParameter ("harm2",       // parameterID
                                      "2nd Harmonic",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (1.0f, 10.0f),    // range
                                      2.0f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("harm3",       // parameterID
                                      "3rd Harmonic",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (1.0f, 10.0f),    // range
                                      3.0f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("harm4",       // parameterID
                                      "4th Harmonic",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (1.0f, 10.0f),    // range
                                      4.0f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("attack",       // parameterID
                                      "Attack",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (0.0f, 1.0f),    // range
                                      0.005f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("decay",       // parameterID
                                      "Decay",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (0.0f, 1.0f),    // range
                                      0.2f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("sustain",       // parameterID
                                      "Sustain",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (0.0f, 1.0f),    // range
                                      0.4f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.createAndAddParameter ("release",       // parameterID
                                      "Release",       // parameter name
                                      String(),     // parameter label (suffix)
                                      NormalisableRange<float> (0.0f, 1.0f),    // range
                                      0.5f,         // default value
                                      nullptr,
                                      nullptr);

    parameters.state = ValueTree (Identifier ("APVTSAddSynth"));
}

PyoAddSynthAudioProcessor::~PyoAddSynthAudioProcessor()
{
}

//==============================================================================
const String PyoAddSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PyoAddSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PyoAddSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double PyoAddSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PyoAddSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PyoAddSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PyoAddSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String PyoAddSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void PyoAddSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PyoAddSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    keyboardState.reset();

    pyo.setup(getTotalNumOutputChannels(), samplesPerBlock, sampleRate);
    pyo.exec(BinaryData::pyoAddSynth_py);


}

void PyoAddSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    keyboardState.reset();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PyoAddSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PyoAddSynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    String attack (*parameters.getRawParameterValue ("attack"));
    String decay (*parameters.getRawParameterValue ("decay"));
    String sustain (*parameters.getRawParameterValue ("sustain"));
    String release (*parameters.getRawParameterValue ("release"));


    const int numSamples = buffer.getNumSamples();

    keyboardState.processNextMidiBuffer (midiMessages, 0, numSamples, true);

    MidiMessage m;
    int time;
    //pyo.midi(status, data 1, data 2)
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
            pyo.midi(143+m.getChannel(), m.getNoteNumber(), m.getVelocity());
        }
        else if (m.isNoteOff())
        {
            pyo.midi(127+m.getChannel(), m.getNoteNumber(), m.getVelocity());
        }
        else if (m.isController())
        {
            pyo.midi(175+m.getChannel(), m.getControllerNumber(), m.getControllerValue());
        }
        else if (m.isAftertouch())
        {
        }
        else if (m.isPitchWheel())
        {
        }
    }

    pyo.value("harm2", *parameters.getRawParameterValue ("harm2"));
    pyo.value("harm3", *parameters.getRawParameterValue ("harm3"));
    pyo.value("harm4", *parameters.getRawParameterValue ("harm4"));
    pyo.exec("synth.envAttack("+attack+")");
    pyo.exec("synth.envDecay("+decay+")");
    pyo.exec("synth.envSustain("+sustain+")");
    pyo.exec("synth.envRelease("+release+")");

    pyo.process(buffer);
}

//==============================================================================
bool PyoAddSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PyoAddSynthAudioProcessor::createEditor()
{
    return new PyoAddSynthAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void PyoAddSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    ScopedPointer<XmlElement> xml (parameters.state.createXml());
        copyXmlToBinary (*xml, destData);
}

void PyoAddSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

        if (xmlState != nullptr)
            if (xmlState->hasTagName (parameters.state.getType()))
                parameters.state = ValueTree::fromXml (*xmlState);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PyoAddSynthAudioProcessor();
}
