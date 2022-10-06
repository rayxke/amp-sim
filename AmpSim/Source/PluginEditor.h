/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AmpKnob.h"
#include "SelectionBox.h"

//==============================================================================
/**
*/
class AmpSimAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AmpSimAudioProcessorEditor (AmpSimAudioProcessor&);
    ~AmpSimAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    /* Helper Functions */
    std::vector<juce::Component*> getComps();
    std::vector<juce::Component*> getKnobs();
    juce::Point<float> getInitialWindowSize () const { return juce::Point<float>(1000, 600); }

    /* Font assets */
    juce::Font ampSectionFont{ 12.0f };
    juce::Font ampSliderFont{ 16.0f };
    juce::Font comboBoxFont{ 16.0f };
    juce::Font noiseGateFont{ 16.0f };
    juce::Font reverbFont{ 16.0f };
    juce::Font bypassedFont{ 16.0f };
    enum FontStyles
    {
        stylePlain = 1,
        styleBold,
        styleItalic,
        numberOfStyles
    };
    
    /* Gain slider */
    AmpKnobRotarySlider preGainSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> preGainAtt;

    /* Filter sliders */
    AmpKnobRotarySlider bassSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bassAtt;
    AmpKnobRotarySlider midSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> midAtt;
    AmpKnobRotarySlider trebleSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> trebleAtt;

    /* Noise gate assets */
    juce::ToggleButton noiseGateToggle;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> noiseGateToggleAtt;
    juce::Slider gateThresholdSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gateThresholdAtt;
    juce::Slider gateRatioSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gateRatioAtt;
    juce::Slider gateAttackSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gateAttackAtt;
    juce::Slider gateReleaseSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gateReleaseAtt;

    /* Waveshaper combo box */
    SelectionBox waveShaperCombo;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> waveShaperAtt;
    
    /* Master volume slider */
    AmpKnobRotarySlider masterVolSlider;
    juce::Font masterVolFont;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> masterVolAtt;
    void waveshaperChanged();
    
    /* Reverb */
    juce::ToggleButton reverbButton;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> reverbButtonAtt;
    juce::Slider reverbRoomSize;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> reverbRoomAtt;
    juce::Slider reverbDamping;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> reverbDampingAtt;
    juce::Slider reverbMix;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> reverbMixAtt;
    juce::Slider reverbWidth;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> reverbWidthAtt;

    /* Convolution combo box */
    SelectionBox convolutionCombo;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> convolutionAtt;
    void convolutionChanged();

    /* Referenced audio processor */
    AmpSimAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpSimAudioProcessorEditor)
};
