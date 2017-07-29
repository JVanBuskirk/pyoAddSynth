# pyoAddSynth
Additive Synth using Juce and Pyo


Audio Units build and work well in some hosts. VST plugins will build, but will not load into any host. I am a novice C++ programmer which probably explains the known issues.

You must have Pyo installed to run the plug-in. http://ajaxsoundstudio.com/software/pyo/

This plug-in is based on:

Olivier Bélanger's Pyo embedded tutorial.

https://github.com/belangeo/pyo/tree/master/embedded/juceplugin

Juce tutorials

https://www.juce.com/tutorials

Redwood Audio's Tutorial

http://www.redwoodaudio.net/Tutorials/juce_for_vst_development__intro3.html

Known Issues

OSX

Audio Units will build and load into Reaper, Logic, Ardour5 but fail to load into Max, Juce Plugin Host, and Tracktion.
VST will build but fails to load into any host
