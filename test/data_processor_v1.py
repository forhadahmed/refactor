# Data processor version 1

import os
import json
import logging

class DataProcessor:
    def __init__(self, config_path):
        self.config_path = config_path
        self.config = None
        self.logger = logging.getLogger(__name__)
        self.data_cache = {}

    def load_config(self):
        if not os.path.exists(self.config_path):
            self.logger.error(f"Config file not found: {self.config_path}")
            return False
        try:
            with open(self.config_path, 'r') as f:
                self.config = json.load(f)
            self.logger.info(f"Config loaded from {self.config_path}")
            return True
        except json.JSONDecodeError as e:
            self.logger.error(f"Invalid JSON in config: {e}")
            return False
        except IOError as e:
            self.logger.error(f"Error reading config: {e}")
            return False

    def process_records(self, records):
        if not records:
            self.logger.warning("No records to process")
            return []
        results = []
        for record in records:
            if not isinstance(record, dict):
                self.logger.warning(f"Skipping invalid record: {record}")
                continue
            if 'id' not in record:
                self.logger.warning("Record missing 'id' field")
                continue
            processed = self._transform_record(record)
            if processed is not None:
                results.append(processed)
                self.data_cache[record['id']] = processed
        self.logger.info(f"Processed {len(results)} records")
        return results

    def _transform_record(self, record):
        try:
            transformed = {
                'id': record['id'],
                'name': record.get('name', 'unknown'),
                'value': record.get('value', 0) * 2,
                'status': 'processed'
            }
            return transformed
        except Exception as e:
            self.logger.error(f"Transform error: {e}")
            return None

    def get_cached(self, record_id):
        if record_id in self.data_cache:
            return self.data_cache[record_id]
        return None

    def clear_cache(self):
        count = len(self.data_cache)
        self.data_cache = {}
        self.logger.info(f"Cleared {count} cached records")
