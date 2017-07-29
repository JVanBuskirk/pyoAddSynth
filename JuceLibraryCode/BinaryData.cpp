/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== pyoAddSynth.py ==================
static const unsigned char temp_binary_data_0[] =
"class AddSynth:\r\n"
"    def __init__(self, harm2 = 2, harm3 = 3, harm4 = 4, attack = 0.005, decay = 0.2, sustain = 0.4, release = 0.5):\r\n"
"        self.harm2 = Sig(harm2)\r\n"
"        self.harm3 = Sig(harm3)\r\n"
"        self.harm4 = Sig(harm4)\r\n"
"        self.attack = attack\r\n"
"        self.decay = decay\r\n"
"        self.sustain = sustain\r\n"
"        self.release = release\r\n"
"\r\n"
"        self.note = Notein(poly=8, scale=1, first=0, last=127)\r\n"
"        self.amp = MidiAdsr(self.note['velocity'], attack=self.attack,\r\n"
"                            decay=self.decay, sustain=self.sustain, release=self.release, mul=.15)\r\n"
"        self.osc1 = Sine(freq = self.note['pitch'], mul = self.amp).mix(1)\r\n"
"        self.osc2 = Sine(freq = self.note['pitch']*self.harm2, mul = self.amp).mix(1)\r\n"
"        self.osc3 = Sine(freq = self.note['pitch']*self.harm3, mul = self.amp).mix(1)\r\n"
"        self.osc4 = Sine(freq = self.note['pitch']*self.harm4, mul = self.amp).mix(1)\r\n"
"        \r\n"
"        self.mix = Mix([self.osc1+self.osc2+self.osc3+self.osc4], voices = 2)\r\n"
"        \r\n"
"    def envAttack(self, att):\r\n"
"        self.amp.setAttack(att)\r\n"
"        return self\r\n"
"    \r\n"
"    def envDecay(self, decay):\r\n"
"        self.amp.setDecay(decay)\r\n"
"        return self\r\n"
"    \r\n"
"    def envSustain(self, sus):\r\n"
"        self.amp.setSustain(sus)\r\n"
"        return self\r\n"
"    \r\n"
"    def envRelease(self, rel):\r\n"
"        self.amp.setRelease(rel)\r\n"
"        return self\r\n"
"        \r\n"
"    def out(self):\r\n"
"        self.mix.out()\r\n"
"        return self\r\n"
"        \r\n"
"    def sig(self):\r\n"
"        return self.mix\r\n"
"        \r\n"
"harm2 = SigTo(2.0, 0.05, 2.0)\r\n"
"harm3 = SigTo(3.0, 0.05, 3.0)\r\n"
"harm4 = SigTo(4.0, 0.05, 4.0)\r\n"
"attack = 0.005\r\n"
"decay = 0.2\r\n"
"sustain = 0.4\r\n"
"release = 0.5\r\n"
"\r\n"
"synth = AddSynth(harm2, harm3, harm4, attack, decay, sustain, release)\r\n"
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
        case 0x7995ee47:  numBytes = 1814; return pyoAddSynth_py;
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
