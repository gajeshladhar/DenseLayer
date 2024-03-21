### <img src="https://cdn-icons-png.flaticon.com/512/1042/1042820.png" height=24 width=24>  Super Resolution v3.0

Super Resolution 3.0 is a project focused on the fusion of Sentinel-2 optical and Sentinel-1 radar satellite data to generate high-resolution super-resolved images. The project utilizes advanced deep learning techniques to enhance the spatial resolution of satellite imagery, providing detailed and accurate insights for various applications such as environmental monitoring, agriculture, and urban planning.<br><br>

<center>
<img src="https://r2.easyimg.io/jpn8qnkjy/screenshot_2024-03-20_230205.png" height=400 width=950>
</center><br><br>

#### <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Jupyter_logo.svg/883px-Jupyter_logo.svg.png" height=20 width=20>  Run Model Inference of SR3 (Jupyter Notebook):
```
Inference Notebook : src/notebooks/inference/inference.ipynb 
```
<br>

#### <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Jupyter_logo.svg/883px-Jupyter_logo.svg.png" height=20 width=20>  SR3 Model Training & Downloading (Jupyter Notebook):
```
Training Notebook : src/notebooks/training/training.ipynb 
Reloading Notebook (S3 Bucket): src/notebooks/training/reloading.ipynb 
New Datacube Generation (Planetary): src/utils/preprocess_datacube.py
```
<br>

#### <img src="https://cdn.icon-icons.com/icons2/1808/PNG/512/command-line_115191.png" height=20 width=20>    Installation & Execution through CMD:
```
1. pip3 install requirements.txt
2. cd src/
3. python3 main.py --bbox xmin,ymin,xmax,ymax --daterange 2023-10-01/2024-03-20 --outpath s3://super-resolution-3.0/inferences/test
```
<br>

#### ⚡ Latest SOTA Features:
```
- Generates 1.25m imagery after every 5 day.
- Get cloud free imagery upto 4 cloudy timestaps.
- STAC APIs Integration for Data Download.
- S3 Bucket Integration for SR3.
- Model Training & Data Downloading Script Integrated.
```

#### A Top Level Folder Structure for Pipelining

    
    ├── src                    
    │   ├── data            # contains downloading dataset & datacube scripts     
    │   ├── models          # contains model architectures
    │   ├── pipelines
    │   │     └── pipeline.py # end-to-end pipeline for SR3
    │   │
    │   ├── notebooks       # contains training & inference notebooks   
    │   └── utils           # contains utility & helper modules

<br>
