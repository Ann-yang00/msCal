#include "PluginProcessor.h"
#include "PluginEditor.h"

Ms_calAudioProcessor::Ms_calAudioProcessor()
    :
    parameters(*this, nullptr, "parameters", {
        std::make_unique <juce::AudioParameterInt>("bpm",
            "BPM",
            50,
            200,
            120)
        }),
    // pointer to the parameter value
    bpmValue(parameters.getRawParameterValue("bpm"))
{   
}
Ms_calAudioProcessor::~Ms_calAudioProcessor()
{
}

//==============================================================================
const juce::String Ms_calAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Ms_calAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Ms_calAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Ms_calAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Ms_calAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Ms_calAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Ms_calAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Ms_calAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Ms_calAudioProcessor::getProgramName (int index)
{
    return {};
}

void Ms_calAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Ms_calAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void Ms_calAudioProcessor::releaseResources()
{
}

bool Ms_calAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return true;
}


void Ms_calAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    
}

//==============================================================================
bool Ms_calAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Ms_calAudioProcessor::createEditor()
{
    return new Ms_calAudioProcessorEditor(*this, parameters);
}

float Ms_calAudioProcessor::baseLength()
{
    // length of a 16th note in ms given the current BPM
    float sixteenthNote_len = 60000 / *bpmValue / 4; 
    return sixteenthNote_len;
}

//==============================================================================
void Ms_calAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Ms_calAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Ms_calAudioProcessor();
}
