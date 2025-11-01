# 🎃 Motion-Activated Halloween Pumpkin (Kypruino / Arduino Project)

Turn a simple 3D-printed pumpkin into a **motion-activated Halloween prop** that flickers, glows, and plays the *Halloween* theme song when someone walks by!

Using a **Kypruino board** (or Arduino UNO), a **PIR motion sensor**, and a **transparent 3D-printed shell**, this project combines electronics, 3D printing, and code to create an interactive decoration that surprises everyone.

---

## 🧠 Introduction

Every now and then you build something that’s more than just a “cool gadget” — it actually *surprises* people.  
That’s exactly what happened when we turned a simple 3D-printed pumpkin into a motion-activated prop.  

Using a transparent printed shell, a compact **Kypruino** board, a **PIR motion sensor**, and a simple light-and-sound sequence, we made a pumpkin that flickers like a candle and then bursts into the first few seconds of the *Halloween* theme song whenever someone walks by.

This repository includes:
- STL model modifications  
- Arduino code  
- Wiring diagram  
- Step-by-step build guide  

---

## 🎯 Why We Built It

Halloween props are fun — but many of them just sit there.  
We wanted something **interactive** that senses motion and reacts with light and sound.

The transparent material adds a layered glowing effect, and with a simple USB-C cable for power, it becomes a reusable decoration illuminated by the built-in NeoPixels on the Kypruino board.

**Goal:**  
Pumpkin shell + flat base for mounting + motion trigger → flicker lights + theme song.

---

## 🧩 Components & Tools

| Component | Description |
|------------|-------------|
| **Kypruino board** | Built-in NeoPixels & buzzer |
| **PIR motion sensor** | Detects motion via infrared |
| **3× male-female DuPont wires** | For connections |
| **USB-C cable** | Power input through rear hole |
| **3D-printed pumpkin shell** | Based on “Jackie Jack-o-Lantern” by BirdBott |
| **Transparent filament (PLA or PETG)** | To let light shine through |
| **Arduino IDE** | Used for programming |

💡 *You can use a standard Arduino UNO if you wire the NeoPixels and buzzer manually.*

---

## ⚡ About the Kypruino

The **Kypruino** is a small, programmable board that brings projects like this to life — it’s the *brain* of the pumpkin.  

Think of it as an enhanced Arduino UNO, with built-in:
- NeoPixel LEDs  
- Buzzer  
- Buttons  
- DAC and sensor ports  

It connects easily to your PC via USB for programming, and once the code is uploaded, it runs automatically — checking for motion, controlling lights, and triggering sound effects.

Learn more about the Kypruino at [robo.com.cy/pages/kypruino](https://robo.com.cy/pages/kypruino).

---

## 👀 PIR Motion Sensor

The **PIR (Passive Infrared)** sensor detects changes in infrared radiation — meaning it can “see” when a person or animal passes by.

- **Sensing angle:** ~100°  
- **Range:** up to 7 m  
- **Voltage:** 4.5–12 V  
- **Adjustments:** sensitivity & time delay (via onboard potentiometers)

Tip: Point the PIR through the pumpkin’s mouth for the best detection!

---

## 🧱 Designing & 3D Printing the Pumpkin

We started with [Jackie Jack-o-Lantern by BirdBott](https://www.thingiverse.com/thing:4613024).

### Modifications:
1. **Flatten the base** for stable mounting of the Kypruino board (double-face tape or screws).  
2. **Add a hole at the back** for routing the USB-C cable.  

You can download our **modified STL** in this repository’s `/3D Models` folder.

The transparent filament allows the internal NeoPixels to glow through beautifully — giving that perfect candle-like flicker.

---

## 🔌 Wiring & Electronics

Inside the shell:

- Place the **Kypruino** with its USB-C port facing backward.  
- Ensure **NeoPixel** and **Buzzer** switches are ON.  
- Mount the **PIR sensor** behind the pumpkin’s eyes or mouth.

### Connections:

| PIR Sensor | Kypruino Pin |
|-------------|---------------|
| VCC | 5V |
| GND | GND |
| OUT | D7 |

Power is supplied via USB-C from the rear hole — keeping everything tidy and hidden.  
For temporary assembly, use double-faced tape. For permanent setups, use screws or standoffs.

---

## 💻 Programming the Effect

The code listens for motion from the PIR sensor and plays the flicker and sound sequence.

**Sequence overview:**
1. Motion detected → LEDs turn orange/red  
2. Brightness randomly varies (75–255) for a candle flicker effect  
3. Buzzer plays the first 4 seconds of the *Halloween* theme  
4. Lights turn off → cooldown period → re-arm  

👉 The full Arduino sketch is available in `/code/kypruino_pumpkin.ino`.

---

## ✨ Final Result & Experience

Once powered via USB-C and placed on a table, the pumpkin patiently waits.  
When motion is detected:
- The LEDs flicker orange like a candle  
- The buzzer plays the spooky tune  
- Then everything fades out again  

Because the shell is transparent, the glow has a soft, ghostly halo.  
People often walk by multiple times just to trigger it again — a sign of a successful interactive prop!

---

## 🚀 Possible Future Enhancements

- Experiment with new **color transitions** or **gradients**  
- Add **custom light sequences**  
- Replace buzzer with a **mini speaker** for richer sound  
- Add a **rechargeable battery** for cordless use  
- Integrate with other sensors for multi-trigger effects  

---

## 🏁 Conclusion

This project brings together 3D printing, electronics, and coding to make something that *comes alive*.  
If you’re looking for a fun, hands-on way to blend art and tech — this is it!

We hope it inspires you to build your own interactive decorations.  
Don’t forget to share your remix with us!

---

## 🙏 Attribution

Original 3D Model:  
**[Jackie Jack-o-Lantern by BirdBott on Thingiverse](https://www.thingiverse.com/thing:4613024)** — thank you for releasing the design!

---

## 📫 Contact & Community

💬 For questions, ideas, or collaborations:  
**support@robo.com.cy**

🌐 Visit [robo.com.cy](https://robo.com.cy)  
Follow us on [Facebook](https://facebook.com/robocy), [Instagram](https://instagram.com/robocy), [YouTube](https://youtube.com/@robocy), and [TikTok](https://tiktok.com/@robocy)

---

**Made with 💘 by ROBO CY**  
_Proudly designed and tested in Cyprus 🇨🇾_
