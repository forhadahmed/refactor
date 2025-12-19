# Data processor version 2 - similar to v1 with variations

import os
import json
import logging

class RecordHandler:
    def __init__(self, settings_path):
        self.settings_path = settings_path
        self.settings = None
        self.logger = logging.getLogger(__name__)
        self.record_cache = {}

    def load_settings(self):
        if not os.path.exists(self.settings_path):
            self.logger.error(f"Settings file not found: {self.settings_path}")
            return False
        try:
            with open(self.settings_path, 'r') as f:
                self.settings = json.load(f)
            self.logger.info(f"Settings loaded from {self.settings_path}")
            return True
        except json.JSONDecodeError as e:
            self.logger.error(f"Invalid JSON in settings: {e}")
            return False
        except IOError as e:
            self.logger.error(f"Error reading settings: {e}")
            return False

    def handle_records(self, records):
        if not records:
            self.logger.warning("No records to handle")
            return []
        output = []
        for record in records:
            if not isinstance(record, dict):
                self.logger.warning(f"Skipping invalid record: {record}")
                continue
            if 'id' not in record:
                self.logger.warning("Record missing 'id' field")
                continue
            handled = self._convert_record(record)
            if handled is not None:
                output.append(handled)
                self.record_cache[record['id']] = handled
        self.logger.info(f"Handled {len(output)} records")
        return output

    def _convert_record(self, record):
        try:
            converted = {
                'id': record['id'],
                'name': record.get('name', 'unknown'),
                'value': record.get('value', 0) * 2,
                'status': 'converted'
            }
            return converted
        except Exception as e:
            self.logger.error(f"Convert error: {e}")
            return None

    def get_from_cache(self, record_id):
        if record_id in self.record_cache:
            return self.record_cache[record_id]
        return None

    def flush_cache(self):
        count = len(self.record_cache)
        self.record_cache = {}
        self.logger.info(f"Flushed {count} cached records")
