#pragma once

//#include <JuceHeader.h>

class myLookAndFeel : public juce::LookAndFeel_V4
{
public:
    myLookAndFeel()
    {
        setColour(juce::Slider::thumbColourId, juce::Colours::white);
        setColour(juce::TableHeaderComponent::backgroundColourId, juce::Colours::black);
        setColour(juce::TextButton::buttonColourId, juce::Colours::lightpink);
        setColour(juce::ScrollBar::thumbColourId, juce::Colours::blue);   
    }
    
    void drawTableHeaderColumn(juce::Graphics& g, juce::TableHeaderComponent& header,
        const juce::String& columnName, int columnId,
        int width, int height, bool isMouseOver, bool isMouseDown,
        int columnFlags) 
    {
        juce::Rectangle<int> area(width, height);
        area.reduce(4, 0);

        g.setColour(juce::Colours::white);
        g.setFont(withDefaultMetrics(juce::FontOptions((float)height * 0.5f, juce::Font::bold)));
        g.drawFittedText(columnName, area, juce::Justification::centred, 1);
    }

};
