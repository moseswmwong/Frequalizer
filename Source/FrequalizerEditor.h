/*
  ==============================================================================

 This is the Frequalizer UI editor

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FrequalizerProcessor.h"


//==============================================================================
/**
*/
class FrequalizerAudioProcessorEditor  : public AudioProcessorEditor,
                                         public ChangeListener
{
public:
    FrequalizerAudioProcessorEditor (FrequalizerAudioProcessor&);
    ~FrequalizerAudioProcessorEditor();

    //==============================================================================

    void paint (Graphics&) override;
    void resized() override;
    void changeListenerCallback (ChangeBroadcaster* sender) override;

    //==============================================================================

    class BandEditor : public Component,
                       public Button::Listener
    {
    public:
        BandEditor (const int i, FrequalizerAudioProcessor& processor);

        void resized () override;

        void updateControls (FrequalizerAudioProcessor::FilterType type);

        void updateSoloState (const bool isSolo);

        void buttonClicked (Button* b) override;

        Path frequencyResponse;
    private:
        int index;
        FrequalizerAudioProcessor& processor;

        GroupComponent      frame;
        ComboBox            filterType;
        TextFormattedSlider frequency;
        TextFormattedSlider quality;
        TextFormattedSlider gain;
        TextButton          solo;
        TextButton          activate;
        OwnedArray<AudioProcessorValueTreeState::ComboBoxAttachment> boxAttachments;
        OwnedArray<AudioProcessorValueTreeState::SliderAttachment> attachments;
        OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> buttonAttachments;
    };


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FrequalizerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FrequalizerAudioProcessorEditor)

    OwnedArray<BandEditor>  bandEditors;

    Rectangle<int>          plotFrame;
    Rectangle<int>          branding;
    Path                    frequencyResponse;

    GroupComponent          frame;
    TextFormattedSlider     output;

    OwnedArray<AudioProcessorValueTreeState::SliderAttachment> attachments;

};
