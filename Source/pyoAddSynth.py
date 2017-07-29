class AddSynth:
    def __init__(self, harm1 = 2, harm2 = 3, harm3 = 4, attack = 0.005, decay = 0.2, sustain = 0.4, release = 0.5):
        self.harm1 = Sig(harm1)
        self.harm2 = Sig(harm2)
        self.harm3 = Sig(harm3)
        self.attack = attack
        self.decay = decay
        self.sustain = sustain
        self.release = release

        self.note = Notein(poly=8, scale=1, first=0, last=127)
        self.amp = MidiAdsr(self.note['velocity'], attack=self.attack,
                            decay=self.decay, sustain=self.sustain, release=self.release, mul=.15)
        self.osc1 = Sine(freq = self.note['pitch'], mul = self.amp).mix(1)
        self.osc2 = Sine(freq = self.note['pitch']*self.harm1, mul = self.amp).mix(1)
        self.osc3 = Sine(freq = self.note['pitch']*self.harm2, mul = self.amp).mix(1)
        self.osc4 = Sine(freq = self.note['pitch']*self.harm3, mul = self.amp).mix(1)
        
        self.mix = Mix([self.osc1+self.osc2+self.osc3+self.osc4], voices = 2)
        
    def envAttack(self, att):
        self.amp.setAttack(att)
        return self
    
    def envDecay(self, decay):
        self.amp.setDecay(decay)
        return self
    
    def envSustain(self, sus):
        self.amp.setSustain(sus)
        return self
    
    def envRelease(self, rel):
        self.amp.setRelease(rel)
        return self
        
    def out(self):
        self.mix.out()
        return self
        
    def sig(self):
        return self.mix
        
harm1 = SigTo(2.0, 0.05, 2.0)
harm2 = SigTo(3.0, 0.05, 3.0)
harm3 = SigTo(4.0, 0.05, 4.0)
attack = 0.005
decay = 0.2
sustain = 0.4
release = 0.5

synth = AddSynth(harm1, harm2, harm3, attack, decay, sustain, release)
comp = Compress(synth.sig(), thresh=-20, ratio=6).out()