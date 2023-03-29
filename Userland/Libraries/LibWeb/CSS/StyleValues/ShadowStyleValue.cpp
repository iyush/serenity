/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2021, Tobias Christiansen <tobyase@serenityos.org>
 * Copyright (c) 2021-2023, Sam Atkins <atkinssj@serenityos.org>
 * Copyright (c) 2022-2023, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "ShadowStyleValue.h"

namespace Web::CSS {

ErrorOr<String> ShadowStyleValue::to_string() const
{
    StringBuilder builder;
    TRY(builder.try_appendff("{} {} {} {} {}", m_properties.color.to_deprecated_string(), TRY(m_properties.offset_x.to_string()), TRY(m_properties.offset_y.to_string()), TRY(m_properties.blur_radius.to_string()), TRY(m_properties.spread_distance.to_string())));
    if (m_properties.placement == ShadowPlacement::Inner)
        TRY(builder.try_append(" inset"sv));
    return builder.to_string();
}

ValueComparingNonnullRefPtr<StyleValue const> ShadowStyleValue::absolutized(CSSPixelRect const& viewport_rect, Gfx::FontPixelMetrics const& font_metrics, CSSPixels font_size, CSSPixels root_font_size, CSSPixels line_height, CSSPixels root_line_height) const
{
    auto absolutized_offset_x = m_properties.offset_x.absolutized(viewport_rect, font_metrics, font_size, root_font_size, line_height, root_line_height);
    auto absolutized_offset_y = m_properties.offset_y.absolutized(viewport_rect, font_metrics, font_size, root_font_size, line_height, root_line_height);
    auto absolutized_blur_radius = m_properties.blur_radius.absolutized(viewport_rect, font_metrics, font_size, root_font_size, line_height, root_line_height);
    auto absolutized_spread_distance = m_properties.spread_distance.absolutized(viewport_rect, font_metrics, font_size, root_font_size, line_height, root_line_height);
    return ShadowStyleValue::create(m_properties.color, absolutized_offset_x, absolutized_offset_y, absolutized_blur_radius, absolutized_spread_distance, m_properties.placement);
}

}