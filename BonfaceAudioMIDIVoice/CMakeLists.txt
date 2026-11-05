cmake_minimum_required(VERSION 3.22)

project(BonfaceAudioMIDIVoice VERSION 1.0.0)

add_subdirectory(../JUCE JUCE)

juce_add_plugin(BonfaceAudioMIDIVoice
    COMPANY_NAME "Bonface Audio"
    PLUGIN_MANUFACTURER_CODE Bnfc
    PLUGIN_CODE Bmav
    FORMATS VST3
    PRODUCT_NAME "Bonface Audio MIDI Voice"
    IS_SYNTH FALSE
    NEEDS_AUDIO_INPUT TRUE
    IS_MIDI_EFFECT FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    COPY_PLUGIN_AFTER_BUILD FALSE
)

target_sources(BonfaceAudioMIDIVoice PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_features(BonfaceAudioMIDIVoice PRIVATE cxx_std_17)

target_link_libraries(BonfaceAudioMIDIVoice PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
)
