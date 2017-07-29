/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== pyoAddSynth.py ==================
static const unsigned char temp_binary_data_0[] =
"class AddSynth:\n"
"    def __init__(self, harm1 = 2, harm2 = 3, harm3 = 4, attack = 0.005, decay = 0.2, sustain = 0.4, release = 0.5):\n"
"        self.harm1 = Sig(harm1)\n"
"        self.harm2 = Sig(harm2)\n"
"        self.harm3 = Sig(harm3)\n"
"        self.attack = attack\n"
"        self.decay = decay\n"
"        self.sustain = sustain\n"
"        self.release = release\n"
"\n"
"        self.note = Notein(poly=8, scale=1, first=0, last=127)\n"
"        self.amp = MidiAdsr(self.note['velocity'], attack=self.attack,\n"
"                            decay=self.decay, sustain=self.sustain, release=self.release, mul=.15)\n"
"        self.osc1 = Sine(freq = self.note['pitch'], mul = self.amp).mix(1)\n"
"        self.osc2 = Sine(freq = self.note['pitch']*self.harm1, mul = self.amp).mix(1)\n"
"        self.osc3 = Sine(freq = self.note['pitch']*self.harm2, mul = self.amp).mix(1)\n"
"        self.osc4 = Sine(freq = self.note['pitch']*self.harm3, mul = self.amp).mix(1)\n"
"        \n"
"        self.mix = Mix([self.osc1+self.osc2+self.osc3+self.osc4], voices = 2)\n"
"        \n"
"    def envAttack(self, att):\n"
"        self.amp.setAttack(att)\n"
"        return self\n"
"    \n"
"    def envDecay(self, decay):\n"
"        self.amp.setDecay(decay)\n"
"        return self\n"
"    \n"
"    def envSustain(self, sus):\n"
"        self.amp.setSustain(sus)\n"
"        return self\n"
"    \n"
"    def envRelease(self, rel):\n"
"        self.amp.setRelease(rel)\n"
"        return self\n"
"        \n"
"    def out(self):\n"
"        self.mix.out()\n"
"        return self\n"
"        \n"
"    def sig(self):\n"
"        return self.mix\n"
"        \n"
"harm1 = SigTo(2.0, 0.05, 2.0)\n"
"harm2 = SigTo(3.0, 0.05, 3.0)\n"
"harm3 = SigTo(4.0, 0.05, 4.0)\n"
"attack = 0.005\n"
"decay = 0.2\n"
"sustain = 0.4\n"
"release = 0.5\n"
"\n"
"synth = AddSynth(harm1, harm2, harm3, attack, decay, sustain, release)\n"
"comp = Compress(synth.sig(), thresh=-20, ratio=6).out()";

const char* pyoAddSynth_py = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x7995ee47:  numBytes = 1762; return pyoAddSynth_py;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "pyoAddSynth_py"
};

}
