/*
    Copyright (C) 2014-2016 Islog

    This file is part of Leosac.

    Leosac is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Leosac is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "IAuditEntry.hpp"
#include "core/auth/AuthFwd.hpp"

namespace Leosac
{
namespace Audit
{
/**
 * Interface that describes an Audit object when a user-related event
 * happens.
 *
 * Possible use case:
 *     + User profile edition.
 *     + User creation/deletion.
 */
class IUserEvent : virtual public IAuditEntry
{
  public:
    /**
     * Set the user that is targeted by the event.
     */
    virtual void target(Auth::UserPtr user) = 0;

    /**
     * An optional JSON representation of the object
     * **before** the event took place.
     */
    virtual void before(const std::string &repr) = 0;

    /**
     * An optional JSON representation of the object
     * **after** the event took place.
     */
    virtual void after(const std::string &repr) = 0;
};
}
}
