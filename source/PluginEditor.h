#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#include "PluginProcessor.h"
#include "tableClass.h"
#include "myLookAndFeel.h"

class Ms_calAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                    public juce::Slider::Listener
{
public:
    Ms_calAudioProcessorEditor(Ms_calAudioProcessor&, juce::AudioProcessorValueTreeState& parameterTree);
    ~Ms_calAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Ms_calAudioProcessor& audioProcessor;
    
    juce::Slider bpmSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment bpmAttachment;
    
    TableComponent myTable;

    myLookAndFeel myLookandFeel;

    void updateTable();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ms_calAudioProcessorEditor)
};
