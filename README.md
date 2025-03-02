# msCal 
![GUI](assets/images/pluginGUI.png)

msCal is a JUCE plugin that calculates the millisecond duration for pre-delay, decay time, and total time based on a given BPM and effect size.

### :abacus: Calculation

For a given BPM, the millisecond duration of a quarter note is calculated as:

`60,000 ms ÷ BPM = duration of a quarter note`

The pre-delay is set to 1/64 of the quarter note duration:

`Pre-delay = (quarter note duration) ÷ 64`

The remaining is the decay time, calculated as:

`Decay time = Total time - Pre-delay`


### :warning: Known Issues
- The plugin does not handle audio signal flow (no output)


### :loudspeaker: Note
This plugin was released using &nbsp;[![](https://github.com/sudara/pamplejuce/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/sudara/pamplejuce/actions)

