#pragma once

#include <juce_audio_utils/juce_audio_utils.h>

class BonfaceAudioMIDIVoiceAudioProcessor : public juce::AudioProcessor
{
public:
    BonfaceAudioMIDIVoiceAudioProcessor();

    ~BonfaceAudioMIDIVoiceAudioProcessor() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock(
        juce::AudioBuffer<float>&,
        juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int) override;
    const juce::String getProgramName(int) override;
    void changeProgramName(int, const juce::String&) override;

    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;

private:
    double currentSampleRate = 44100.0;
    static constexpr int analysisBufferSize = 8192;
    float analysisBuffer[analysisBufferSize] = {};
    int writePosition = 0;
    int samplesSinceAnalysis = 0;
    int activeMidiNote = -1;
    int silenceBlocks = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        BonfaceAudioMIDIVoiceAudioProcessor)
};
