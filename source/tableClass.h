#pragma once
//#include <JuceHeader.h>
#include <cmath>
#include <vector>

class TableModel : public juce::TableListBoxModel
{
public:
    TableModel() 
    {
    }

    int getNumRows() override
    {
        return columnHeadings.size(); 
    }

    void paintRowBackground(juce::Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override
    {
        g.fillAll(juce::Colours::black);
    }

    void paintCell(juce::Graphics& g, int rowNumber, int columnId, int width, int height, bool isSelected) override
    {
        g.setColour(juce::Colours::white);
        g.setFont(14.0f);
        
        juce::String cellText;

        cellText = tableVals[rowNumber][columnId];

        g.drawText(cellText, 2, 0, width - 4, height, juce::Justification::centred);
    }
    
    void calMatrix(float sixteenthBase)
    {
        tableVals.clear();
        // sixteenthBase is the total effect time for the 1/16 note
        // calculate and populate the whole matrix (tableVals) using this

        for (int row = 0; row < columnHeadings.size(); row++) {
            // generate a string array for each row
            juce::Array<juce::String> currentRow;
            // adds the 'effect size' string
            currentRow.add(columnHeadings[row]);

            float totalTime = sixteenthBase * pow(2, row);
            float preDelay = totalTime / 64;
            float decayTime = totalTime - preDelay;
            std::vector <float> result = { preDelay, decayTime, totalTime };

            for (int i = 0; i < result.size(); i++) {
                juce::String newString = juce::String(result[i], 2);
                newString += " ms";
                currentRow.add(newString);
            }
            tableVals.add(currentRow);
        } 
    }

private:
    // an array of string array
    juce::Array <juce::Array <juce::String>> tableVals;
    std::vector<juce::String> columnHeadings = { "Sixteenth Note (1/16)", "Eighth Note (1/8)", "Tight Ambience (1/4 Note)", "Small Room (1/2 Note)", "Large Room (1 Bar)", "Hall (2 Bars)" };
};


class TableComponent : public juce::Component
{
public:
    TableComponent()
    {
        addAndMakeVisible(table);
        model = TableModel();
        table.setModel(&model);
        
        // Add columns
        table.getHeader().addColumn("Effect Size", 0, 180); // column width
        table.getHeader().addColumn("Pre Delay", 1, 100);
        table.getHeader().addColumn("Decay Time", 2, 100);
        table.getHeader().addColumn("Total Time", 3, 100);

        table.setBounds(getLocalBounds());
    }

    void resized() 
    {
        table.setBounds(getLocalBounds());
    }
    
    void update_val(float newBase)
    {
        model.calMatrix(newBase);
        table.updateContent();
        table.repaint();
    }

private:
    TableModel model;
    juce::TableListBox table;
};
