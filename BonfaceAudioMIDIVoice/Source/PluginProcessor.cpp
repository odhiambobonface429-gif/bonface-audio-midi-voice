#include "PluginProcessor.h"
#include "PluginEditor.h"

BonfaceAudioMIDIVoiceAudioProcessor::BonfaceAudioMIDIVoiceAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::mono(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

void BonfaceAudioMIDIVoiceAudioProcessor::prepareToPlay(double, int)
{
}

void BonfaceAudioMIDIVoiceAudioProcessor::releaseResources()
{
}

void BonfaceAudioMIDIVoiceAudioProcessor::processBlock(
    juce::AudioBuffer<float>& buffer,
    juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    midiMessages.clear();

    // Temporary clean build: pitch detection will be added next.
}

juce::AudioProcessorEditor*
BonfaceAudioMIDIVoiceAudioProcessor::createEditor()
{
    return new BonfaceAudioMIDIVoiceAudioProcessorEditor(*this);
}

bool BonfaceAudioMIDIVoiceAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String BonfaceAudioMIDIVoiceAudioProcessor::getName() const
{
    return "Bonface Audio MIDI Voice";
}

bool BonfaceAudioMIDIVoiceAudioProcessor::acceptsMidi() const
{
    return true;
}

bool BonfaceAudioMIDIVoiceAudioProcessor::producesMidi() const
{
    return true;
}

bool BonfaceAudioMIDIVoiceAudioProcessor::isMidiEffect() const
{
    return false;
}

double BonfaceAudioMIDIVoiceAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BonfaceAudioMIDIVoiceAudioProcessor::getNumPrograms()
{
    return 1;
}

int BonfaceAudioMIDIVoiceAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BonfaceAudioMIDIVoiceAudioProcessor::setCurrentProgram(int)
{
}

const juce::String
BonfaceAudioMIDIVoiceAudioProcessor::getProgramName(int)
{
    return {};
}

void BonfaceAudioMIDIVoiceAudioProcessor::changeProgramName(
    int, const juce::String&)
{
}

void BonfaceAudioMIDIVoiceAudioProcessor::getStateInformation(
    juce::MemoryBlock&)
{
}

void BonfaceAudioMIDIVoiceAudioProcessor::setStateInformation(
    const void*, int)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BonfaceAudioMIDIVoiceAudioProcessor();
