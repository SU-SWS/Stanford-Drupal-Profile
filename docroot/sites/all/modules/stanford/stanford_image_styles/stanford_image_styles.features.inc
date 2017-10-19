<?php
/**
 * @file
 * stanford_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function stanford_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 12-col-banner.
  $styles['12-col-banner'] = array(
    'label' => '12-col-banner',
    'effects' => array(
      17 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2340,
          'height' => 740,
        ),
        'weight' => 1,
      ),
      18 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 12-col-banner-tall.
  $styles['12-col-banner-tall'] = array(
    'label' => '12-col-banner-tall',
    'effects' => array(
      19 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1000,
        ),
        'weight' => 1,
      ),
      20 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 3-col-header.
  $styles['3-col-header'] = array(
    'label' => '3-col-header',
    'effects' => array(
      21 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 540,
          'height' => 200,
        ),
        'weight' => 1,
      ),
      22 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 4-col-header.
  $styles['4-col-header'] = array(
    'label' => '4-col-header',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 280,
        ),
        'weight' => 1,
      ),
      24 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 6-col-banner.
  $styles['6-col-banner'] = array(
    'label' => '6-col-banner',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 660,
        ),
        'weight' => 1,
      ),
      26 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 6-col-banner-short.
  $styles['6-col-banner-short'] = array(
    'label' => '6-col-banner-short',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 540,
        ),
        'weight' => 1,
      ),
      28 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 6-col-banner-tall.
  $styles['6-col-banner-tall'] = array(
    'label' => '6-col-banner-tall',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 640,
        ),
        'weight' => 1,
      ),
      30 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 6-col-photo-landscape.
  $styles['6-col-photo-landscape'] = array(
    'label' => '6-col-photo-landscape',
    'effects' => array(
      90 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 860,
        ),
        'weight' => 1,
      ),
      91 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 8-col-banner.
  $styles['8-col-banner'] = array(
    'label' => '8-col-banner',
    'effects' => array(
      88 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1540,
          'height' => 660,
        ),
        'weight' => 1,
      ),
      89 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 8-col-banner-short.
  $styles['8-col-banner-short'] = array(
    'label' => '8-col-banner-short',
    'effects' => array(
      86 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1540,
          'height' => 540,
        ),
        'weight' => 1,
      ),
      87 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 8-col-banner-tall.
  $styles['8-col-banner-tall'] = array(
    'label' => '8-col-banner-tall',
    'effects' => array(
      84 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1540,
          'height' => 880,
        ),
        'weight' => 1,
      ),
      85 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 9-col-banner.
  $styles['9-col-banner'] = array(
    'label' => '9-col-banner',
    'effects' => array(
      82 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1740,
          'height' => 660,
        ),
        'weight' => 1,
      ),
      83 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 9-col-banner-short.
  $styles['9-col-banner-short'] = array(
    'label' => '9-col-banner-short',
    'effects' => array(
      80 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1740,
          'height' => 540,
        ),
        'weight' => 1,
      ),
      81 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: banner-850x400.
  $styles['banner-850x400'] = array(
    'label' => 'banner (850x400)',
    'effects' => array(
      78 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1700,
          'height' => 800,
        ),
        'weight' => 1,
      ),
      79 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: full-width-banner.
  $styles['full-width-banner'] = array(
    'label' => 'Full Width Banner (Scale and Crop 1600x600)',
    'effects' => array(
      76 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 3200,
          'height' => 1200,
        ),
        'weight' => 1,
      ),
      77 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: full-width-banner-short.
  $styles['full-width-banner-short'] = array(
    'label' => 'full-width-banner-short',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 3200,
          'height' => 1000,
        ),
        'weight' => 2,
      ),
      14 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: half-page-profile.
  $styles['half-page-profile'] = array(
    'label' => 'Half Page Profile (Scale and Crop 600x700)',
    'effects' => array(
      73 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 1400,
        ),
        'weight' => 1,
      ),
      74 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: header_scale_850x400.
  $styles['header_scale_850x400'] = array(
    'label' => 'Header (Scale 850x400)',
    'effects' => array(
      71 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1700,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      72 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: huge-landscape.
  $styles['huge-landscape'] = array(
    'label' => 'Huge Landscape (Scale and Crop 1500x1200)',
    'effects' => array(
      69 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 3000,
          'height' => 2400,
        ),
        'weight' => 1,
      ),
      70 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: icon-profile.
  $styles['icon-profile'] = array(
    'label' => 'icon-profile',
    'effects' => array(
      67 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 130,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      68 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: icon-scaled.
  $styles['icon-scaled'] = array(
    'label' => 'icon-scaled',
    'effects' => array(
      65 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      66 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: icon-square.
  $styles['icon-square'] = array(
    'label' => 'icon-square',
    'effects' => array(
      63 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
      64 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large-landscape.
  $styles['large-landscape'] = array(
    'label' => 'large-landscape',
    'effects' => array(
      61 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 550,
        ),
        'weight' => 1,
      ),
      62 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large-landscape-scaled.
  $styles['large-landscape-scaled'] = array(
    'label' => 'large-landscape-scaled',
    'effects' => array(
      59 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 540,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      60 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large-profile.
  $styles['large-profile'] = array(
    'label' => 'large-profile',
    'effects' => array(
      57 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 540,
          'height' => 630,
        ),
        'weight' => 1,
      ),
      58 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large-profile-scaled.
  $styles['large-profile-scaled'] = array(
    'label' => 'large-profile-scaled',
    'effects' => array(
      55 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      56 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large-scaled.
  $styles['large-scaled'] = array(
    'label' => 'large-scaled',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 270,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large-square.
  $styles['large-square'] = array(
    'label' => 'large-square',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 270,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: med-landscape.
  $styles['med-landscape'] = array(
    'label' => 'med-landscape',
    'effects' => array(
      53 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 540,
          'height' => 400,
        ),
        'weight' => 1,
      ),
      54 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: med-landscape-scaled.
  $styles['med-landscape-scaled'] = array(
    'label' => 'med-landscape-scaled',
    'effects' => array(
      51 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 540,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      52 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: med-profile.
  $styles['med-profile'] = array(
    'label' => 'med-profile',
    'effects' => array(
      49 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 400,
        ),
        'weight' => 1,
      ),
      50 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: med-profile-scaled.
  $styles['med-profile-scaled'] = array(
    'label' => 'med-profile-scaled',
    'effects' => array(
      47 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 540,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      48 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: med-square.
  $styles['med-square'] = array(
    'label' => 'med-square',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page-width.
  $styles['page-width'] = array(
    'label' => 'page-width',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sm-landscape.
  $styles['sm-landscape'] = array(
    'label' => 'sm-landscape',
    'effects' => array(
      43 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 250,
        ),
        'weight' => 1,
      ),
      44 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: sm-landscape-scaled.
  $styles['sm-landscape-scaled'] = array(
    'label' => 'sm-landscape-scaled',
    'effects' => array(
      41 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      42 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: sm-profile.
  $styles['sm-profile'] = array(
    'label' => 'sm-profile',
    'effects' => array(
      39 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 260,
        ),
        'weight' => 1,
      ),
      40 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: sm-profile-scaled.
  $styles['sm-profile-scaled'] = array(
    'label' => 'sm-profile-scaled',
    'effects' => array(
      37 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 220,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      38 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: sm-scaled.
  $styles['sm-scaled'] = array(
    'label' => 'sm-scaled',
    'effects' => array(
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 120,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sm-square.
  $styles['sm-square'] = array(
    'label' => 'sm-square',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: thmb-landscape.
  $styles['thmb-landscape'] = array(
    'label' => 'thmb-landscape',
    'effects' => array(
      35 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 150,
        ),
        'weight' => 1,
      ),
      36 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: thmb-profile.
  $styles['thmb-profile'] = array(
    'label' => 'thmb-profile',
    'effects' => array(
      33 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 170,
        ),
        'weight' => 1,
      ),
      34 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: thmb-square.
  $styles['thmb-square'] = array(
    'label' => 'thmb-square',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 1,
      ),
      32 => array(
        'name' => 'image_hires',
        'data' => array(),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
