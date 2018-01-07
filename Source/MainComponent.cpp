/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#include <memory>
#include "FrequencyControl.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent()
    {
        frequencyControl = std::unique_ptr<FrequencyControl>(new FrequencyControl());
        addAndMakeVisible(frequencyControl.get());
        //setSize (400, 100);
        setBounds(frequencyControl->getBounds());

        // specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
    //==============================================================================
    void updateAngleDelta()
    {
        frequency = frequencyControl->getFrequencyValue();
        double cyclesPerSample = frequency / currentSampleRate;
        //
        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
        
        currentAngle = 0.0;
        currentSampleRate = sampleRate;
        updateAngleDelta();
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        bufferToFill.clearActiveBufferRegion();
        //
        updateAngleDelta();
        //
        const float level = 0.125f;
        //
        const int qtyOutputChannels = bufferToFill.buffer->getNumChannels();
        //
        //qtySamples = bufferToFill.numSamples;
        //
        for(int channel = 0; channel < qtyOutputChannels; ++channel)
        {
            outputWriteBuffer.push_back( bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample) );
        }
        //
        /*
        int previousSample = 0;
        std::vector<int> samples(bufferToFill.numSamples);
        std::for_each(samples.begin(), samples.end(), [&](int sample)
        {
            sample = previousSample;
            currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta;
            //
            std::for_each(outputWriteBuffer.begin(), outputWriteBuffer.end(), [&](float* buffer)
            {
                buffer[sample] = currentSample * level;
            });
            ++previousSample;
        });
         */
        //
        /*
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta;
            //
            std::for_each(outputWriteBuffer.begin(), outputWriteBuffer.end(), [&](float* buffer)
            {
                    buffer[sample] = currentSample * level;
            });
        }
         */
        //
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta;
            //
            for(int channel = 0; channel < qtyOutputChannels; ++channel)
            {
                outputWriteBuffer[channel][sample] = currentSample * level;
            }
        }
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
    }


private:
    //==============================================================================

    // Your private member variables go here...
    
    double currentSampleRate;
    double angleDelta;
    double currentAngle;
    float currentSample;
    double frequency;
    int qtySamples;

    std::vector<float*> outputWriteBuffer;

    std::unique_ptr<FrequencyControl> frequencyControl;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }
