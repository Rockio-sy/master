import numpy as np
from PIL import Image
import tkinter as tk

# Function to encode message into image
def encode():
    src = enter_a.get() # Get source image file name from input field
    message = enter_b.get() # Get message to hide from input field
    dest = enter_c.get() # Get destination image file name from input field
    img = Image.open(src, "r") # Open source image in read mode
    width, height = img.size # Get width and height of the image
    array = np.array(list(img.getdata())) # Convert image data into a numpy array
    n = 3 # Number of color channels in the image (RGB)
    m = 0 # Initialize a variable to keep track of current pixel
    total_pixels = array.size // n # Total number of pixels in the image
    message += "#####" # Add delimiter to the end of the message
    b_message = ''.join([format(ord(i), "08b") for i in message]) # Convert message to binary
    req_pixels = len(b_message) # Calculate number of pixels required to hide the entire message
    if req_pixels > total_pixels:
        print("ERROR: Need larger file size")
    else:
        index = 7 # Initialize bit index to start from the highest bit
        for p in range(total_pixels):
            for q in range(m, n):
                if index < req_pixels:
                    array[p][q] = int(bin(array[p][q])[2:9] + b_message[index], 2)
                    # Modify the least significant bit of the pixel
                    if index % 8 == 0:
                        index += 16 # Skip 8 bits after every 8 bits of message
                    index -= 1 # Move to next bit of message
        array = array.reshape(height, width, n) # Reshape the array to original image dimensions
        enc_img = Image.fromarray(np.uint8(array)) # Convert the numpy array back to image
        enc_img.save(dest) # Save the encoded image to destination file
        hidden_message("Image Encoded Successfully") # Show success message


# Function to decode message from image
def decode():
    src = enter_d.get() # Get source image file name from input field
    img = Image.open(src, 'r') # Open source image in read mode
    array = np.array(list(img.getdata())) # Convert image data into a numpy array
    n = 3 # Number of color channels in the image (RGB)
    m = 0 # Initialize a variable to keep track of current pixel
    total_pixels = array.size // n # Total number of pixels in the image
    hidden_bits = "" # Initialize a string to store hidden bits
    for p in range(total_pixels):
        for q in range(m, n):
            hidden_bits += (bin(array[p][q])[2:][-1]) # Extract the least significant bit of each pixel
    hidden_bits = [(hidden_bits[i+7:i:-1] + hidden_bits[i]) for i in range(0, len(hidden_bits), 8)]
    # Rearrange the hidden bits to get the original message in binary
    message = "" # Initialize a string to store the decoded message
    for i in range(len(hidden_bits)):
        if message[-5:] == "#####": # Check if delimiter is found in the message
            break
        else:
            message += chr(int(hidden_bits[i], 2)) # Convert binary to ASCII and add to the message string
            if "#####" in message: # Check
                hidden_message(message[:-5])


# Define a function for displaying a hidden message in a new window
def hidden_message(message):
    error = tk.Toplevel(window)  # Create a new top-level window
    info = "Message:" + message
    error0 = tk.Label(error, text=info)  # Create a label to display the message
    error0.grid(column=0, row=3)  # Place the label in the window
    error.title('Message')  # Set the title of the window
    error.minsize(width=300, height=100)  # Set the minimum size of the window
    error.maxsize(width=300, height=100)  # Set the maximum size of the window

"""Create a main window"""


window = tk.Tk()
window.title("Lab_03")  # Set the title of the main window

# Create labels and entry fields for user input
text_a = tk.Label(window, text="Enter image name: ")
enter_a = tk.Entry(window)
text_b = tk.Label(window, text="Enter Message to Hide: ")
enter_b = tk.Entry(window)
text_c = tk.Label(window, text="Enter the name of new encoded image: ")
enter_c = tk.Entry(window)
text_d = tk.Label(window, text="Enter the name of image that you want to decode: ")
enter_d = tk.Entry(window)

# Place the labels and entry fields in the main window using a grid layout
text_a.grid(column=0, row=0)
enter_a.grid(columnspan=2, column=1, row=0)
text_b.grid(column=0, row=1)
enter_b.grid(columnspan=2, column=1, row=1)
text_c.grid(column=0, row=2)
enter_c.grid(columnspan=2, column=1, row=2)
text_d.grid(column=0, row=3)
enter_d.grid(columnspan=2, column=1, row=3)

# Create buttons for encoding and decoding, and specify their respective command functions
button_point = tk.Button(window, text="Encode", command=encode)
button_point.grid(column=1, row=4)
button_x = tk.Button(window, text="Decode", command=decode)
button_x.grid(column=2, row=4)

window.mainloop()  # Start the main event loop to display the window and handle user input
