// Test 2 : float[]
func float[] creer_notes() {
    float notes[4];
    notes[0] = 15.5;
    notes[1] = 18.0;
    notes[2] = 12.5;
    notes[3] = 16.0;
    return notes;
}

float[] mes_notes = creer_notes();
print("Notes:");
print(mes_notes[0]);
print(mes_notes[1]);
print(mes_notes[2]);
print(mes_notes[3]);
