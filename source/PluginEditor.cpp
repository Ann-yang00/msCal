#include "PluginProcessor.h"
#include "PluginEditor.h"


Ms_calAudioProcessorEditor::Ms_calAudioProcessorEditor (Ms_calAudioProcessor& p, 
                                juce::AudioProcessorValueTreeState& parameterTree)
    : AudioProcessorEditor (&p), audioProcessor (p), 
    bpmSlider(juce::Slider::IncDecButtons, juce::Slider::TextBoxBelow),
    bpmAttachment(parameterTree, "bpm", bpmSlider), myTable()
{   
    juce::LookAndFeel::setDefaultLookAndFeel(&myLookandFeel);
    bpmSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 50, 30);
    addAndMakeVisible(bpmSlider);
    bpmSlider.setTextValueSuffix(" BPM");   
    bpmSlider.addListener(this);

    setResizable(false,
        false);
    setSize(650, 210);

    addAndMakeVisible(myTable);
}

Ms_calAudioProcessorEditor::~Ms_calAudioProcessorEditor()
{
}

//==============================================================================
void Ms_calAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void Ms_calAudioProcessorEditor::resized()
{
    bpmSlider.setBounds(25, 40, 60, 55);    
    myTable.setBounds(105, 25, 500, 160);
    updateTable();
}


void Ms_calAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    updateTable();
}

void Ms_calAudioProcessorEditor::updateTable()
{
    myTable.update_val(audioProcessor.baseLength());
}
