#pragma once

#include <juce_audio_utils/juce_audio_utils.h>
#include "PluginProcessor.h"

class BonfaceAudioMIDIVoiceAudioProcessorEditor
    : public juce::AudioProcessorEditor
{
public:
    explicit BonfaceAudioMIDIVoiceAudioProcessorEditor(
        BonfaceAudioMIDIVoiceAudioProcessor&);

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    juce::Label titleLabel;
    juce::Label statusLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        BonfaceAudioMIDIVoiceAudioProcessorEditor)
};
