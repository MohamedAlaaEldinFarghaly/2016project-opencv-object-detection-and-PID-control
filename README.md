# 2016project-opencv-object-detection-and-PID-control

For more information
https://drive.google.com/open?id=0B_8VnTs-yxuEMTNzWl90SW1ES3M

Algorithm of detecting the ball’s position:
1- Setup OPENCV library on Visual Studio.
2- Open the Webcam with a window of 640 x 480 size for all windows.
3- Define storage memory for input images from the video.
4- Convert the image from RGB to HSV to differentiate the ball intensity with the background.
5- Applying different filter to the image to detect the ball precisely and accurately.
6- Smoothing the processed image.
7- Open Threshold bar to control the background of the image and use it to detect the ball
alone without any disturbance of any noise or unwanted background.
8- Creating a circle of the ball, drawing a small green circle at center of detected object,
drawing a red circle around the detected object and returning back the radius and the x and y
coordinate of its center.
9- Mapping the size of the webcam window 640 x 480 to fit the size of the plate which is 40 x
40 cm so that the coordinate of the ball is correctly processed and sent to the PID control to
the Actuators.

Integrating the system:
When the system was set to work together some problems arose and needed solutions specifically
with delivering the data to and from the Arduino:
