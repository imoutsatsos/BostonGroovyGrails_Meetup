CellProfiler Pipeline: http://www.cellprofiler.org
Version:3
DateRevision:20160503183100
GitHash:ac0529e
ModuleCount:46
HasImagePlaneDetails:False

LoadData:[module_num:1|svn_version:\'Unknown\'|variable_revision_number:6|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Input data file location:URL\x7C
    URL of the file:http\x3A//localhost\x3A8080/job/Contribute_Pipeline/102//artifact/example_image_list.csv
    Load images based on this data?:Yes
    Base image location:None\x7C
    Process just a range of rows?:No
    Rows to process:1,100000
    Group images by metadata?:Yes
    Select metadata tags for grouping:Barcode,RowNumber,Column,FieldIndex
    Rescale intensities?:Yes

IdentifyPrimaryObjects:[module_num:2|svn_version:\'Unknown\'|variable_revision_number:10|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:DNA
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):90,500
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:50
    Suppress local maxima that are closer than this minimum allowed distance:60
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:After both thresholding and declumping
    Automatically calculate size of smoothing filter for declumping?:No
    Automatically calculate minimum allowed distance between local maxima?:No
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5.0
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Threshold setting version:1
    Threshold strategy:Automatic
    Thresholding method:Otsu
    Select the smoothing method for thresholding:Automatic
    Threshold smoothing scale:1.0
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:0.01
    Manual threshold:0.0
    Select the measurement to threshold with:None
    Select binary image:None
    Masking objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10
    Use default parameters?:Default
    Lower outlier fraction:0.05
    Upper outlier fraction:0.05
    Averaging method:Mean
    Variance method:Standard deviation
    # of deviations:2.0

ExpandOrShrinkObjects:[module_num:3|svn_version:\'Unknown\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input objects:Nuclei
    Name the output objects:ShrunkenNuclei
    Select the operation:Shrink objects by a specified number of pixels
    Number of pixels by which to expand or shrink:5
    Fill holes in objects so that all objects shrink to a single point?:No
    Retain the outlines of the identified objects?:No
    Name the outline image:ShrunkenNucleiOutlines

IdentifySecondaryObjects:[module_num:4|svn_version:\'Unknown\'|variable_revision_number:9|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:False|wants_pause:False]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells
    Select the method to identify the secondary objects:Watershed - Image
    Select the input image:MBNL1
    Number of pixels by which to expand the primary objects:10
    Regularization factor:0.05
    Name the outline image:SecondaryOutlines
    Retain outlines of the identified secondary objects?:No
    Discard secondary objects touching the border of the image?:No
    Discard the associated primary objects?:No
    Name the new primary objects:FilteredNuclei
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:FilteredNucleiOutlines
    Fill holes in identified objects?:Yes
    Threshold setting version:1
    Threshold strategy:Global
    Thresholding method:Otsu
    Select the smoothing method for thresholding:No smoothing
    Threshold smoothing scale:1.0
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:0.01
    Manual threshold:0.0
    Select the measurement to threshold with:None
    Select binary image:None
    Masking objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10
    Use default parameters?:Default
    Lower outlier fraction:0.05
    Upper outlier fraction:0.05
    Averaging method:Mean
    Variance method:Standard deviation
    # of deviations:2.0

MaskImage:[module_num:5|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:RNA
    Name the output image:MaskedRNA
    Use objects or an image as a mask?:Objects
    Select object for mask:ShrunkenNuclei
    Select image for mask:None
    Invert the mask?:No

CorrectIlluminationCalculate:[module_num:6|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:MaskedRNA
    Name the output image:IllumRNA
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Median Filter
    Method to calculate smoothing filter size:Manually
    Approximate object size:10
    Smoothing filter size:30
    Retain the averaged image?:No
    Name the averaged image:IllumBlueAvg
    Retain the dilated image?:No
    Name the dilated image:IllumBlueDilated
    Automatically calculate spline parameters?:Yes
    Background mode:auto
    Number of spline points:5
    Background threshold:2.0
    Image resampling factor:2.0
    Maximum number of iterations:40
    Residual value for convergence:0.001

CorrectIlluminationApply:[module_num:7|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:MaskedRNA
    Name the output image:CorrRNA
    Select the illumination function:IllumRNA
    Select how the illumination function is applied:Divide

IdentifyPrimaryObjects:[module_num:8|svn_version:\'Unknown\'|variable_revision_number:10|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:CorrRNA
    Name the primary objects to be identified:RNA
    Typical diameter of objects, in pixel units (Min,Max):5,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7.0
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:After declumping only
    Automatically calculate size of smoothing filter for declumping?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5.0
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Threshold setting version:1
    Threshold strategy:Global
    Thresholding method:RobustBackground
    Select the smoothing method for thresholding:Automatic
    Threshold smoothing scale:1
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:0.01
    Manual threshold:0.0
    Select the measurement to threshold with:None
    Select binary image:None
    Masking objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10
    Use default parameters?:Custom
    Lower outlier fraction:0.05
    Upper outlier fraction:0.05
    Averaging method:Median
    Variance method:Median absolute deviation
    # of deviations:2.0

Align:[module_num:9|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the alignment method:Mutual Information
    Crop mode:Keep size
    Select the first input image:RNA
    Name the first output image:AlignedRNA
    Select the second input image:MBNL1
    Name the second output image:AlignedMBNL1

MaskImage:[module_num:10|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:AlignedMBNL1
    Name the output image:MaskedMBNL1
    Use objects or an image as a mask?:Objects
    Select object for mask:ShrunkenNuclei
    Select image for mask:None
    Invert the mask?:No

CorrectIlluminationCalculate:[module_num:11|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:MaskedMBNL1
    Name the output image:IllumMBNL1
    Select how the illumination function is calculated:Regular
    Dilate objects in the final averaged image?:No
    Dilation radius:1
    Block size:60
    Rescale the illumination function?:Yes
    Calculate function for each image individually, or based on all images?:Each
    Smoothing method:Median Filter
    Method to calculate smoothing filter size:Manually
    Approximate object size:10
    Smoothing filter size:30
    Retain the averaged image?:No
    Name the averaged image:IllumBlueAvg
    Retain the dilated image?:No
    Name the dilated image:IllumBlueDilated
    Automatically calculate spline parameters?:Yes
    Background mode:auto
    Number of spline points:5
    Background threshold:2.0
    Image resampling factor:2.0
    Maximum number of iterations:40
    Residual value for convergence:0.001

CorrectIlluminationApply:[module_num:12|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:MaskedMBNL1
    Name the output image:CorrMBLN1
    Select the illumination function:IllumMBNL1
    Select how the illumination function is applied:Divide

IdentifyPrimaryObjects:[module_num:13|svn_version:\'Unknown\'|variable_revision_number:10|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:CorrMBLN1
    Name the primary objects to be identified:MBNL1
    Typical diameter of objects, in pixel units (Min,Max):5,40
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7.0
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:After declumping only
    Automatically calculate size of smoothing filter for declumping?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5.0
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Threshold setting version:1
    Threshold strategy:Global
    Thresholding method:RobustBackground
    Select the smoothing method for thresholding:Automatic
    Threshold smoothing scale:1
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:0.01
    Manual threshold:0.0
    Select the measurement to threshold with:None
    Select binary image:None
    Masking objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10
    Use default parameters?:Custom
    Lower outlier fraction:0.05
    Upper outlier fraction:0.05
    Averaging method:Median
    Variance method:Median absolute deviation
    # of deviations:5.0

MaskObjects:[module_num:14|svn_version:\'Unknown\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select objects to be masked:MBNL1
    Name the masked objects:MaskedMBNL1
    Mask using a region defined by other objects or by binary image?:Objects
    Select the masking object:RNA
    Select the masking image:None
    Handling of objects that are partially masked:Remove depending on overlap
    Fraction of object that must overlap:0.5
    Numbering of resulting objects:Renumber
    Retain outlines of the resulting objects?:No
    Name the outline image:MaskedOutlines
    Invert the mask?:No

FilterObjects:[module_num:15|svn_version:\'Unknown\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:True]
    Name the output objects:CoFoci
    Select the object to filter:MBNL1
    Select the filtering mode:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Elsewhere...\x7C
    Rules file name:rules.txt
    Class number:1
    Measurement count:1
    Additional object count:0
    Assign overlapping child to:Both parents
    Select the measurement to filter by:Children_MaskedMBNL1_Count
    Filter using a minimum measurement value?:Yes
    Minimum value:1.0
    Filter using a maximum measurement value?:No
    Maximum value:1.0

ConvertObjectsToImage:[module_num:16|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:True]
    Select the input objects:MBNL1
    Name the output image:BinaryMBNL1
    Select the color format:Binary (black & white)
    Select the colormap:Default

ConvertObjectsToImage:[module_num:17|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input objects:RNA
    Name the output image:BinaryRNA
    Select the color format:Binary (black & white)
    Select the colormap:Default

ImageMath:[module_num:18|svn_version:\'Unknown\'|variable_revision_number:4|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Operation:Add
    Raise the power of the result by:1.0
    Multiply the result by:1.0
    Add to result:0.0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:BinaryRNA_MBNL1
    Image or measurement?:Image
    Select the first image:BinaryRNA
    Multiply the first image by:1.0
    Measurement:
    Image or measurement?:Image
    Select the second image:BinaryMBNL1
    Multiply the second image by:1.0
    Measurement:

IdentifyPrimaryObjects:[module_num:19|svn_version:\'Unknown\'|variable_revision_number:10|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:BinaryRNA_MBNL1
    Name the primary objects to be identified:MergedFoci
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7.0
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Never
    Automatically calculate size of smoothing filter for declumping?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5.0
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Threshold setting version:1
    Threshold strategy:Manual
    Thresholding method:Otsu
    Select the smoothing method for thresholding:Automatic
    Threshold smoothing scale:1.0
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:0.01
    Manual threshold:0.5
    Select the measurement to threshold with:None
    Select binary image:None
    Masking objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Method to calculate adaptive window size:Image size
    Size of adaptive window:10
    Use default parameters?:Default
    Lower outlier fraction:0.05
    Upper outlier fraction:0.05
    Averaging method:Mean
    Variance method:Standard deviation
    # of deviations:2.0

MeasureObjectSizeShape:[module_num:20|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select objects to measure:CoFoci
    Select objects to measure:Nuclei
    Calculate the Zernike features?:No

MeasureImageIntensity:[module_num:21|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the image to measure:CorrMBLN1
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:CoFoci
    Select the image to measure:CorrRNA
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:CoFoci
    Select the image to measure:CorrMBLN1
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:MBNL1
    Select the image to measure:CorrRNA
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:MBNL1
    Select the image to measure:CorrMBLN1
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:RNA
    Select the image to measure:CorrRNA
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:RNA
    Select the image to measure:CorrMBLN1
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:MergedFoci
    Select the image to measure:CorrRNA
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:MergedFoci

MeasureCorrelation:[module_num:22|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Hidden:2
    Hidden:3
    Select an image to measure:CorrMBLN1
    Select an image to measure:CorrRNA
    Set threshold as percentage of maximum intensity for the images:15.0
    Select where to measure correlation:Both
    Select an object to measure:Nuclei
    Select an object to measure:CoFoci
    Select an object to measure:MergedFoci

MaskImage:[module_num:23|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:CorrMBLN1
    Name the output image:MaskedCorrMBNL1
    Use objects or an image as a mask?:Objects
    Select object for mask:MergedFoci
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:24|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:CorrRNA
    Name the output image:MaskedCorrRNA
    Use objects or an image as a mask?:Objects
    Select object for mask:MergedFoci
    Select image for mask:None
    Invert the mask?:No

MeasureCorrelation:[module_num:25|svn_version:\'Unknown\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Hidden:2
    Hidden:1
    Select an image to measure:MaskedCorrMBNL1
    Select an image to measure:MaskedCorrRNA
    Set threshold as percentage of maximum intensity for the images:15.0
    Select where to measure correlation:Across entire image
    Select an object to measure:Nuclei

MeasureImageAreaOccupied:[module_num:26|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:True]
    Hidden:5
    Measure the area occupied in a binary image, or in objects?:Objects
    Select objects to measure:MBNL1
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:None
    Measure the area occupied in a binary image, or in objects?:Objects
    Select objects to measure:CoFoci
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:None
    Measure the area occupied in a binary image, or in objects?:Objects
    Select objects to measure:RNA
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:None
    Measure the area occupied in a binary image, or in objects?:Objects
    Select objects to measure:Nuclei
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:None
    Measure the area occupied in a binary image, or in objects?:Objects
    Select objects to measure:MergedFoci
    Retain a binary image of the object regions?:No
    Name the output binary image:Stain
    Select a binary image to measure:None

MeasureObjectIntensity:[module_num:27|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Hidden:2
    Select an image to measure:CorrRNA
    Select an image to measure:CorrMBLN1
    Select objects to measure:CoFoci
    Select objects to measure:MergedFoci

MeasureObjectIntensity:[module_num:28|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Hidden:1
    Select an image to measure:DNA
    Select objects to measure:Nuclei

MeasureObjectIntensity:[module_num:29|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:False|wants_pause:False]
    Hidden:3
    Select an image to measure:DNA
    Select an image to measure:RNA
    Select an image to measure:MBNL1
    Select objects to measure:Cells

CalculateMath:[module_num:30|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Name the output measurement:Norm_CoFoci_count
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Count_CoFoci
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_Nuclei
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Take log10 of result?:No
    Multiply the result by:1.0
    Raise the power of result by:1.0
    Add to the result:0.0
    Constrain the result to a lower bound?:No
    Enter the lower bound:0.0
    Constrain the result to an upper bound?:No
    Enter the upper bound:1.0

CalculateMath:[module_num:31|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Name the output measurement:Norm_MBNL1_count
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Count_MBNL1
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_Nuclei
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Take log10 of result?:No
    Multiply the result by:1.0
    Raise the power of result by:1.0
    Add to the result:0.0
    Constrain the result to a lower bound?:No
    Enter the lower bound:0.0
    Constrain the result to an upper bound?:No
    Enter the upper bound:1.0

CalculateMath:[module_num:32|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Name the output measurement:Norm_RNA_count
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Count_RNA
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_Nuclei
    Multiply the above operand by:1.0
    Raise the power of above operand by:1.0
    Take log10 of result?:No
    Multiply the result by:1.0
    Raise the power of result by:1.0
    Add to the result:0.0
    Constrain the result to a lower bound?:No
    Enter the lower bound:0.0
    Constrain the result to an upper bound?:No
    Enter the upper bound:1.0

RelateObjects:[module_num:33|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input child objects:MergedFoci
    Select the input parent objects:Nuclei
    Calculate child-parent distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:34|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input child objects:CoFoci
    Select the input parent objects:Nuclei
    Calculate child-parent distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:35|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input child objects:RNA
    Select the input parent objects:Nuclei
    Calculate child-parent distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:36|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input child objects:MBNL1
    Select the input parent objects:Nuclei
    Calculate child-parent distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

GrayToColor:[module_num:37|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:False|wants_pause:False]
    Select a color scheme:RGB
    Select the image to be colored red:MBNL1
    Select the image to be colored green:RNA
    Select the image to be colored blue:DNA
    Name the output image:ColorImage
    Relative weight for the red image:1.0
    Relative weight for the green image:1.0
    Relative weight for the blue image:1.0
    Select the image to be colored cyan:Leave this black
    Select the image to be colored magenta:Leave this black
    Select the image to be colored yellow:Leave this black
    Select the image that determines brightness:Leave this black
    Relative weight for the cyan image:1.0
    Relative weight for the magenta image:1.0
    Relative weight for the yellow image:1.0
    Relative weight for the brightness image:1.0
    Hidden:1
    Image name:None
    Color:#ff0000
    Weight:1.0

RescaleIntensity:[module_num:38|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:DNA
    Name the output image:RescaledDNA
    Rescaling method:Choose specific values to be reset to the full intensity range
    Method to calculate the minimum intensity:Custom
    Method to calculate the maximum intensity:Custom
    Lower intensity limit for the input image:0.0
    Upper intensity limit for the input image:1.0
    Intensity range for the input image:0.0,0.05
    Intensity range for the output image:0.0,1.0
    Method to rescale pixels below the lower limit:Set to zero
    Custom value for pixels below lower limit:0.0
    Method to rescale pixels above the upper limit:Set to one
    Custom value for pixels above upper limit:0.0
    Select image to match in maximum intensity:None
    Divisor value:1.0
    Divisor measurement:None

RescaleIntensity:[module_num:39|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:RNA
    Name the output image:RescaledRNA
    Rescaling method:Choose specific values to be reset to the full intensity range
    Method to calculate the minimum intensity:Custom
    Method to calculate the maximum intensity:Custom
    Lower intensity limit for the input image:0.0
    Upper intensity limit for the input image:1.0
    Intensity range for the input image:0.0,0.01
    Intensity range for the output image:0.0,1.0
    Method to rescale pixels below the lower limit:Set to zero
    Custom value for pixels below lower limit:0.0
    Method to rescale pixels above the upper limit:Set to one
    Custom value for pixels above upper limit:0.0
    Select image to match in maximum intensity:None
    Divisor value:1.0
    Divisor measurement:None

RescaleIntensity:[module_num:40|svn_version:\'Unknown\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the input image:MBNL1
    Name the output image:RescaledMBNL1
    Rescaling method:Choose specific values to be reset to the full intensity range
    Method to calculate the minimum intensity:Custom
    Method to calculate the maximum intensity:Custom
    Lower intensity limit for the input image:0.0
    Upper intensity limit for the input image:1.0
    Intensity range for the input image:0.0,0.02
    Intensity range for the output image:0.0,1.0
    Method to rescale pixels below the lower limit:Set to zero
    Custom value for pixels below lower limit:0.0
    Method to rescale pixels above the upper limit:Set to one
    Custom value for pixels above upper limit:0.0
    Select image to match in maximum intensity:None
    Divisor value:1.0
    Divisor measurement:None

OverlayOutlines:[module_num:41|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Display outlines on a blank image?:No
    Select image on which to display outlines:RescaledDNA
    Name the output image:OverlayDNA
    Outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:None
    Select outline color:yellow
    Load outlines from an image or objects?:Objects
    Select objects to display:Nuclei

OverlayOutlines:[module_num:42|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Display outlines on a blank image?:No
    Select image on which to display outlines:RescaledRNA
    Name the output image:OverlayRNA
    Outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:None
    Select outline color:yellow
    Load outlines from an image or objects?:Objects
    Select objects to display:RNA
    Select outlines to display:None
    Select outline color:blue
    Load outlines from an image or objects?:Objects
    Select objects to display:Nuclei

OverlayOutlines:[module_num:43|svn_version:\'Unknown\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Display outlines on a blank image?:No
    Select image on which to display outlines:RescaledMBNL1
    Name the output image:OverlayMBNL1
    Outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:None
    Select outline color:yellow
    Load outlines from an image or objects?:Objects
    Select objects to display:MaskedMBNL1
    Select outlines to display:None
    Select outline color:blue
    Load outlines from an image or objects?:Objects
    Select objects to display:Nuclei

Tile:[module_num:44|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select an input image:OverlayDNA
    Name the output image:TiledImage
    Tile assembly method:Within cycles
    Final number of rows:1
    Final number of columns:3
    Image corner to begin tiling:top left
    Direction to begin tiling:row
    Use meander mode?:No
    Automatically calculate number of rows?:No
    Automatically calculate number of columns?:Yes
    Select an additional image to tile:OverlayRNA
    Select an additional image to tile:OverlayMBNL1

SaveImages:[module_num:45|svn_version:\'Unknown\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the type of image to save:Image
    Select the image to save:TiledImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:None
    Enter single file name:\\\\g<RowNumber>_\\\\g<Column>_\\\\g<FieldIndex>
    Number of digits:4
    Append a suffix to the image file name?:No
    Text to append to the image name:
    Saved file format:png
    Output file location:Default Output Folder sub-folder\x7Coutlines/\\\\g<Barcode>
    Image bit depth:8-bit integer
    Overwrite existing files without warning?:Yes
    When to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Record the file and path information to the saved image?:No
    Create subfolders in the output folder?:No
    Base image folder:Elsewhere...\x7C
    Saved movie format:avi

ExportToSpreadsheet:[module_num:46|svn_version:\'Unknown\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D|batch_state:array(\x5B\x5D, dtype=uint8)|enabled:True|wants_pause:False]
    Select the column delimiter:Comma (",")
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the measurements to export:No
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder\x7C
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurement types?:No
    :
    Representation of Nan/Inf:Null
    Add a prefix to file names?:No
    Filename prefix:MyExpt_
    Overwrite existing files without warning?:Yes
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:Image_\\\\g<Barcode>_\\\\g<RowNumber>_\\\\g<Column>_\\\\g<FieldIndex>.csv
    Use the object name for the file name?:No
    Data to export:Nuclei
    Combine these object measurements with those of the previous object?:No
    File name:Nuclei_\\\\g<Barcode>_\\\\g<RowNumber>_\\\\g<Column>_\\\\g<FieldIndex>.csv
    Use the object name for the file name?:No
