#include "PluginEditor.h"

BonfaceAudioMIDIVoiceAudioProcessorEditor::
BonfaceAudioMIDIVoiceAudioProcessorEditor(
    BonfaceAudioMIDIVoiceAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(400, 250);

    titleLabel.setText(
        "BONFACE AUDIO MIDI VOICE",
        juce::dontSendNotification);
    titleLabel.setFont(juce::Font(22.0f, juce::Font::bold));
    titleLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(titleLabel);

    statusLabel.setText(
        "Voice to MIDI - Ready",
        juce::dontSendNotification);
    statusLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(statusLabel);
}

void BonfaceAudioMIDIVoiceAudioProcessorEditor::paint(
    juce::Graphics& g)
{
    g.fillAll(juce::Colour(25, 25, 35));
}

void BonfaceAudioMIDIVoiceAudioProcessorEditor::resized()
{
    titleLabel.setBounds(20, 60, 360, 50);
    statusLabel.setBounds(20, 130, 360, 40);
}
